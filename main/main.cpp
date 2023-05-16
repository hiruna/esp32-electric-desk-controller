
#include <math.h>
#include <stdio.h>

#include "bdc_motor.h"
#include "driver/adc.h"
#include "driver/gpio.h"
#include "driver/pulse_cnt.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "sdkconfig.h"

static const char* TAG = "esp32-electric-desk-controller";

#define MOTOR_DRIVER_I_SENS_ADC_UNIT ADC_UNIT_1
#define MOTOR_DRIVER_I_SENS_FWD_CHAN ADC_CHANNEL_6
#define MOTOR_DRIVER_I_SENS_REV_CHAN ADC_CHANNEL_7
#define MOTOR_DRIVER_I_SENS_ADC_ATTEN ADC_ATTEN_DB_11

#define ESP_INTR_FLAG_DEFAULT 0

#define BDC_MCPWM_TIMER_RESOLUTION_HZ 10000000                                       // 10MHz, 1 tick = 0.1us
#define BDC_MCPWM_FREQ_HZ 25000                                                      // 25KHz PWM
#define BDC_MCPWM_DUTY_TICK_MAX (BDC_MCPWM_TIMER_RESOLUTION_HZ / BDC_MCPWM_FREQ_HZ)  // ~400 // maximum value we can set for the duty cycle, in ticks
#define BDC_MCPWM_GPIO_A 25
#define BDC_MCPWM_GPIO_B 26

#define BDC_ENCODER_GPIO_A 12
#define BDC_ENCODER_GPIO_B 14
#define BDC_ENCODER_PCNT_HIGH_LIMIT 3280
#define BDC_ENCODER_PCNT_LIMIT_OVERFLOW_STEP 5
#define BDC_ENCODER_PCNT_LOW_LIMIT -5

#define MOTOR_ENCODER_COUNTS_PER_ROTATION 160
#define MOTOR_NO_LOAD_SPEED_RPM 95
#define MOTOR_RATED_SPEED_RPM 85

#define DESK_MIN_HEIGHT_MM 730
#define DESK_MAX_HEIGHT_MM 1200

/*
 TODO:

 Set high current alarms for motor driver
 ADC1_CHANNEL_6 (GPIO34)
 ADC1_CHANNEL_7 (GPIO35)

*/
static const float MM_PER_MOTOR_ENC_COUNT = 0.136;  // 1 pulse count ~ 0.136mm

int MOTOR_ENC_LOOP_PERIOD_MS = 10;  // calculate the motor speed every 10ms
int MOTOR_EXPECTED_SPEED_RPM = 50;

typedef struct {
    bdc_motor_handle_t motor;
    pcnt_unit_handle_t pcnt_encoder;
    int pulses;
    int cur_pulse_count;
    int prev_pulse_count;
    int64_t cur_pulse_count_time_ms;
    int64_t prev_pulse_count_time_ms;
    float rpm;
    float distance_mm;
    int watch_point_value;
    pcnt_unit_zero_cross_mode_t zero_cross_mode;
    QueueHandle_t pcnt_event_queue;
} motor_control_context_t;

// gpio/pin definitions
const gpio_num_t GPIO_BTN_UP = GPIO_NUM_4;
const gpio_num_t GPIO_BTN_DOWN = GPIO_NUM_5;
const gpio_num_t GPIO_BTN_SET = GPIO_NUM_13;
const uint64_t GPIO_BTN_UP_DOWN_SET_BIT_MASK = ((1ULL << GPIO_BTN_UP) | (1ULL << GPIO_BTN_DOWN) | (1ULL << GPIO_BTN_SET));

const gpio_num_t GPIO_MOTOR_DRIVER_ENABLE = GPIO_NUM_32;
const uint64_t GPIO_MOTOR_DRIVER_ENABLE_BIT_MASK = (1ULL << GPIO_MOTOR_DRIVER_ENABLE);

// task queue for handling button(s) gpio events
static QueueHandle_t gpio_btn_evt_queue = NULL;

int counter = 0;
bdc_motor_handle_t motor = NULL;
pcnt_unit_handle_t pcnt_unit = NULL;
adc_oneshot_unit_handle_t motor_driver_i_sens_adc_handle;

static bool motor_enc_pcnt_on_reach(pcnt_unit_handle_t unit, const pcnt_watch_event_data_t* edata, void* user_ctx) {
    BaseType_t high_task_wakeup;
    motor_control_context_t* ctx = (motor_control_context_t*)user_ctx;
    // send event data to queue, from this interrupt callback
    xQueueSendFromISR(ctx->pcnt_event_queue, edata, &high_task_wakeup);
    return (high_task_wakeup == pdTRUE);
}

float set_speed = 0;

int get_motor_driver_i_sens_fwd_adc_raw() {
    int adc_raw;
    adc_oneshot_read(motor_driver_i_sens_adc_handle, MOTOR_DRIVER_I_SENS_FWD_CHAN, &adc_raw);
    return adc_raw;
}

int get_motor_driver_i_sens_rev_adc_raw() {
    int adc_raw;
    adc_oneshot_read(motor_driver_i_sens_adc_handle, MOTOR_DRIVER_I_SENS_REV_CHAN, &adc_raw);
    return adc_raw;
}

static void motor_enc_loop_cp(void* args) {
    motor_control_context_t* ctx = (motor_control_context_t*)args;
    bdc_motor_handle_t motor = ctx->motor;

    static int cur_pulse_count = 0;
    int64_t cur_pulse_count_time_ms = esp_timer_get_time() / 1000;
    pcnt_unit_get_count(ctx->pcnt_encoder, &cur_pulse_count);

    ctx->cur_pulse_count = cur_pulse_count;
    ctx->cur_pulse_count_time_ms = cur_pulse_count_time_ms;

    float count_diff = cur_pulse_count - ctx->prev_pulse_count;
    float count_time_diff = cur_pulse_count_time_ms - ctx->prev_pulse_count_time_ms;

    ctx->distance_mm = cur_pulse_count * MM_PER_MOTOR_ENC_COUNT;
    if (count_time_diff >= MOTOR_ENC_LOOP_PERIOD_MS) {
        // Calculate revolutions per minute
        ctx->rpm = (float)(count_diff) / (count_time_diff) * ((float)1000 / MOTOR_ENC_LOOP_PERIOD_MS) * 60;
        ctx->rpm /= MOTOR_ENC_LOOP_PERIOD_MS;
        // ESP_LOGI(TAG, "timeMillis=%lld,rpm=%f,set_speed=%f,prevCountTimeMillis=%lld,prevCount=%d,curCount=%d\n", cur_pulse_count_time_ms, rpm, set_speed, prev_pulse_count_time_ms, prev_pulse_count, cur_pulse_count);
        // printf("%lld %f %f %lld %d %d\n", cur_pulse_count_time_ms, rpm, set_speed, prev_pulse_count_time_ms, prev_pulse_count, cur_pulse_count);
        ESP_LOGI(TAG, "cur_pulse_count_time_ms: %lld, cur_pulse_count: %d, rpm: %f, distance_mm: %f, i_sens_fwd_adc_raw: %d, i_sense_rev_adc_raw: %d\n", cur_pulse_count_time_ms, cur_pulse_count, ctx->rpm, ctx->distance_mm, get_motor_driver_i_sens_fwd_adc_raw(), get_motor_driver_i_sens_rev_adc_raw());
        if (cur_pulse_count != ctx->prev_pulse_count) {
            ctx->prev_pulse_count = cur_pulse_count;
            ctx->prev_pulse_count_time_ms = cur_pulse_count_time_ms;
        }
    }
}

void enable_motor_driver() {
    // if (gpio_get_level(GPIO_MOTOR_DRIVER_ENABLE) == 0) {
    ESP_LOGI(TAG, "enable_motor_driver");
    gpio_set_level(GPIO_MOTOR_DRIVER_ENABLE, 1);
    //}
}

void disable_motor_driver() {
    // if (gpio_get_level(GPIO_MOTOR_DRIVER_ENABLE) == 1) {
    ESP_LOGI(TAG, "disable_motor_driver");
    gpio_set_level(GPIO_MOTOR_DRIVER_ENABLE, 0);
    // }
}

// isr event handler for buttons (up/down)
static void IRAM_ATTR gpio_btn_event_handler(void* arg) {
    uint32_t gpio_num = (uint32_t)arg;
    xQueueSendFromISR(gpio_btn_evt_queue, &gpio_num, NULL);
}

// task for button isr events
static void gpio_btn_event_task(void* arg) {
    gpio_num_t io_num;
    for (;;) {
        if (xQueueReceive(gpio_btn_evt_queue, &io_num, portMAX_DELAY)) {
            if (gpio_get_level(GPIO_BTN_UP) == 1 && gpio_get_level(GPIO_BTN_DOWN) == 0) {
                ESP_LOGI(TAG, "button up pressed");
                enable_motor_driver();
                bdc_motor_forward(motor);
                bdc_motor_set_speed(motor, (uint32_t)200);
            } else if (gpio_get_level(GPIO_BTN_DOWN) == 1 && gpio_get_level(GPIO_BTN_UP) == 0) {
                ESP_LOGI(TAG, "button down pressed");
                enable_motor_driver();
                bdc_motor_reverse(motor);
                bdc_motor_set_speed(motor, (uint32_t)200);
            } else if (gpio_get_level(GPIO_BTN_DOWN) == 0 && gpio_get_level(GPIO_BTN_UP) == 0 && gpio_get_level(GPIO_BTN_SET) == 1) {
                ESP_LOGI(TAG, "button SET is pressed");
                pcnt_unit_clear_count(pcnt_unit);
            } else {
                ESP_LOGI(TAG, "button released");
                disable_motor_driver();
            }
            printf("GPIO[%d] intr, val: %d\n", io_num, gpio_get_level(io_num));
        }
    }
}

void init_motor_driver_current_sens_adc() {
    //-------------ADC1 Init---------------//
    // adc_oneshot_unit_handle_t motor_driver_i_sens_adc_handle;
    adc_oneshot_unit_init_cfg_t motor_driver_i_sens_adc_init_cfg = {
        .unit_id = MOTOR_DRIVER_I_SENS_ADC_UNIT,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&motor_driver_i_sens_adc_init_cfg, &motor_driver_i_sens_adc_handle));

    //-------------ADC1 Config---------------//
    adc_oneshot_chan_cfg_t motor_driver_i_sens_adc_oneshot_cfg = {
        .atten = MOTOR_DRIVER_I_SENS_ADC_ATTEN,
        .bitwidth = ADC_BITWIDTH_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(motor_driver_i_sens_adc_handle, MOTOR_DRIVER_I_SENS_FWD_CHAN, &motor_driver_i_sens_adc_oneshot_cfg));
    ESP_ERROR_CHECK(adc_oneshot_config_channel(motor_driver_i_sens_adc_handle, MOTOR_DRIVER_I_SENS_REV_CHAN, &motor_driver_i_sens_adc_oneshot_cfg));

    //-------------ADC1 Calibration Init---------------//
    // adc_cali_handle_t adc1_cali_handle = NULL;
    // bool do_calibration1 = example_adc_calibration_init(MOTOR_DRIVER_I_SENS_ADC_UNIT, MOTOR_DRIVER_I_SENS_ADC_ATTEN, &adc1_cali_handle);
}

void setup_motor_driver_en_gpio() {
    ESP_LOGI(TAG, "configuring motor driver gpio...");
    gpio_config_t gpio_btn_conf{
        GPIO_MOTOR_DRIVER_ENABLE_BIT_MASK,
        GPIO_MODE_OUTPUT,
        GPIO_PULLUP_DISABLE,
        GPIO_PULLDOWN_DISABLE,
        GPIO_INTR_DISABLE};
    esp_err_t err = gpio_config(&gpio_btn_conf);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error configuring gpio: %s", esp_err_to_name(err));
    }

    gpio_set_level(GPIO_MOTOR_DRIVER_ENABLE, 0);
}
void setup_motor_driver() {
    setup_motor_driver_en_gpio();
    init_motor_driver_current_sens_adc();
}

void setup_buttons() {
    ESP_LOGI(TAG, "configuring gpio buttons...");
    gpio_config_t gpio_btn_conf{
        GPIO_BTN_UP_DOWN_SET_BIT_MASK,
        GPIO_MODE_INPUT,
        GPIO_PULLUP_DISABLE,
        GPIO_PULLDOWN_ENABLE,
        GPIO_INTR_ANYEDGE};

    esp_err_t err = gpio_config(&gpio_btn_conf);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error configuring gpio: %s", esp_err_to_name(err));
    }

    ESP_LOGI(TAG, "create gpio btn event queue...");
    // create a queue to handle gpio event from isr
    gpio_btn_evt_queue = xQueueCreate(10, sizeof(uint32_t));

    ESP_LOGI(TAG, "start gpio btn event task...");
    // start gpio task
    xTaskCreate(gpio_btn_event_task, "gpio_btn_event_task", 2048, NULL, 10, NULL);

    ESP_LOGI(TAG, "install gpio isr service...");
    // install gpio isr service
    err = gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error installing gpio isr service: %s", esp_err_to_name(err));
    }

    ESP_LOGI(TAG, "adding isr handler for btn up...");
    // hook isr handler for button 'up'
    err = gpio_isr_handler_add(GPIO_BTN_UP, gpio_btn_event_handler, (void*)GPIO_BTN_UP);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error adding isr handler for btn up: %s", esp_err_to_name(err));
    }

    ESP_LOGI(TAG, "adding isr handler for btn down...");
    // hook isr handler for button 'down'
    err = gpio_isr_handler_add(GPIO_BTN_DOWN, gpio_btn_event_handler, (void*)GPIO_BTN_DOWN);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error adding isr handler for btn down: %s", esp_err_to_name(err));
    }

    ESP_LOGI(TAG, "adding isr handler for btn set...");
    // hook isr handler for button 'down'
    err = gpio_isr_handler_add(GPIO_BTN_SET, gpio_btn_event_handler, (void*)GPIO_BTN_SET);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error adding isr handler for btn set: %s", esp_err_to_name(err));
    }
}

extern "C" {
void app_main(void);
}

void app_main() {
    setup_buttons();
    setup_motor_driver();
    ESP_LOGI(TAG, "Create DC motor");
    bdc_motor_config_t motor_config = {
        .pwma_gpio_num = BDC_MCPWM_GPIO_A,
        .pwmb_gpio_num = BDC_MCPWM_GPIO_B,
        .pwm_freq_hz = BDC_MCPWM_FREQ_HZ,
    };
    bdc_motor_mcpwm_config_t mcpwm_config = {
        .group_id = 0,
        .resolution_hz = BDC_MCPWM_TIMER_RESOLUTION_HZ,
    };
    ESP_ERROR_CHECK(bdc_motor_new_mcpwm_device(&motor_config, &mcpwm_config, &motor));

    static motor_control_context_t motor_ctrl_ctx = {
        .motor = motor,
        .pcnt_encoder = NULL,
        .pcnt_event_queue = xQueueCreate(10, sizeof(int)),
    };

    ESP_LOGI(TAG, "Init pcnt driver to decode rotary signal");
    pcnt_unit_config_t unit_config = {
        .low_limit = BDC_ENCODER_PCNT_LOW_LIMIT,
        .high_limit = BDC_ENCODER_PCNT_HIGH_LIMIT,
        .flags = {
            .accum_count = true,  // enable counter accumulation
        },
    };

    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &pcnt_unit));
    pcnt_glitch_filter_config_t filter_config = {
        .max_glitch_ns = 1000,
    };
    ESP_ERROR_CHECK(pcnt_unit_set_glitch_filter(pcnt_unit, &filter_config));

    pcnt_channel_handle_t pcnt_chan_a = NULL;
    pcnt_chan_config_t chan_a_config = {
        .edge_gpio_num = BDC_ENCODER_GPIO_A,
        .level_gpio_num = BDC_ENCODER_GPIO_B,
    };
    ESP_ERROR_CHECK(pcnt_new_channel(pcnt_unit, &chan_a_config, &pcnt_chan_a));

    pcnt_channel_handle_t pcnt_chan_b = NULL;
    pcnt_chan_config_t chan_b_config = {
        .edge_gpio_num = BDC_ENCODER_GPIO_B,
        .level_gpio_num = BDC_ENCODER_GPIO_A,
    };
    ESP_ERROR_CHECK(pcnt_new_channel(pcnt_unit, &chan_b_config, &pcnt_chan_b));

    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_chan_a, PCNT_CHANNEL_EDGE_ACTION_DECREASE, PCNT_CHANNEL_EDGE_ACTION_INCREASE));
    ESP_ERROR_CHECK(pcnt_channel_set_level_action(pcnt_chan_a, PCNT_CHANNEL_LEVEL_ACTION_KEEP, PCNT_CHANNEL_LEVEL_ACTION_INVERSE));
    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_chan_b, PCNT_CHANNEL_EDGE_ACTION_INCREASE, PCNT_CHANNEL_EDGE_ACTION_DECREASE));
    ESP_ERROR_CHECK(pcnt_channel_set_level_action(pcnt_chan_b, PCNT_CHANNEL_LEVEL_ACTION_KEEP, PCNT_CHANNEL_LEVEL_ACTION_INVERSE));
    // ESP_ERROR_CHECK(pcnt_unit_add_watch_point(pcnt_unit, BDC_ENCODER_PCNT_HIGH_LIMIT));
    // ESP_ERROR_CHECK(pcnt_unit_add_watch_point(pcnt_unit, BDC_ENCODER_PCNT_LOW_LIMIT));
    int watch_points[] = {BDC_ENCODER_PCNT_LOW_LIMIT, 0, BDC_ENCODER_PCNT_HIGH_LIMIT - BDC_ENCODER_PCNT_LIMIT_OVERFLOW_STEP, BDC_ENCODER_PCNT_HIGH_LIMIT};
    for (size_t i = 0; i < sizeof(watch_points) / sizeof(watch_points[0]); i++) {
        ESP_ERROR_CHECK(pcnt_unit_add_watch_point(pcnt_unit, watch_points[i]));
    }
    pcnt_event_callbacks_t pcnt_cbs = {
        .on_reach = motor_enc_pcnt_on_reach,  // accumulate the overflow in the callback
    };
    ESP_ERROR_CHECK(pcnt_unit_register_event_callbacks(pcnt_unit, &pcnt_cbs, &motor_ctrl_ctx));

    ESP_ERROR_CHECK(pcnt_unit_enable(pcnt_unit));
    ESP_ERROR_CHECK(pcnt_unit_clear_count(pcnt_unit));
    ESP_ERROR_CHECK(pcnt_unit_start(pcnt_unit));
    motor_ctrl_ctx.pcnt_encoder = pcnt_unit;

    ESP_LOGI(TAG, "Create a timer to do motor encoder calculation periodically");
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = motor_enc_loop_cp,
        .arg = &motor_ctrl_ctx,
        .name = "motor_enc_loop"};
    esp_timer_handle_t motor_enc_loop_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &motor_enc_loop_timer));

    ESP_LOGI(TAG, "Enable motor");
    ESP_ERROR_CHECK(bdc_motor_enable(motor));
    ESP_LOGI(TAG, "Brake motor");
    ESP_ERROR_CHECK(bdc_motor_brake(motor));
    ESP_LOGI(TAG, "Motor foward...");
    bdc_motor_forward(motor);
    ESP_LOGI(TAG, "Start motor speed loop");
    ESP_ERROR_CHECK(esp_timer_start_periodic(motor_enc_loop_timer, MOTOR_ENC_LOOP_PERIOD_MS / portTICK_PERIOD_MS));
    int event_count = 0;
    int pulse_count = 0;
    pcnt_watch_event_data_t event_data;
    while (1) {
        ESP_ERROR_CHECK(pcnt_unit_get_count(motor_ctrl_ctx.pcnt_encoder, &pulse_count));
        if (pulse_count == BDC_ENCODER_PCNT_LIMIT_OVERFLOW_STEP * 2 || pulse_count == BDC_ENCODER_PCNT_HIGH_LIMIT - BDC_ENCODER_PCNT_LIMIT_OVERFLOW_STEP) {
            bdc_motor_set_speed(motor, 80);
        }
        if (pulse_count == 0) {
            bdc_motor_coast(motor);
            pcnt_unit_clear_count(pcnt_unit);
        } else if (pulse_count == BDC_ENCODER_PCNT_HIGH_LIMIT) {
            bdc_motor_coast(motor);
        }
        if (xQueueReceive(motor_ctrl_ctx.pcnt_event_queue, &event_data, pdMS_TO_TICKS(1000))) {
            ESP_LOGI(TAG, "Watch point event, count: %d | zero cross mode: %d", event_data.watch_point_value, event_data.zero_cross_mode);
        } else {
            ESP_LOGI(TAG, "Pulse count: %d", pulse_count);
        }
    }
}
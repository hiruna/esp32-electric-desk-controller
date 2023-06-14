/* 
 * Based on https://github.com/hiruna/lv_port_esp32/blob/develop/lvgl_8.3.7_idf_5.2/main/main.c
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "lvgl.h"

#include "driver/pulse_cnt.h"
#include "driver/gpio.h"

#include "lvgl_helpers.h"
#include "ui/ui.h"
#include "ui/ui_events.c"
#if defined CONFIG_USE_LV_TOUCH_CALIBRATION

#include "lv_tc.h"
#include "lv_tc_screen.h"

#ifndef USE_CUSTOM_LV_TC_COEFFICIENTS

#include "esp_nvs_tc.h"

#endif
#endif

/*********************
 *      DEFINES
 *********************/
#define TAG "ElectricDeskControllerUI"
#define LV_TICK_PERIOD_MS 1

#define EXAMPLE_PCNT_HIGH_LIMIT 100
#define EXAMPLE_PCNT_LOW_LIMIT  -100

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

const gpio_num_t GPIO_CTRL_PANEL_ENC_A = GPIO_NUM_4;
const gpio_num_t GPIO_CTRL_PANEL_ENC_B = GPIO_NUM_5;
const gpio_num_t GPIO_CTRL_PANEL_ENC_BTN = GPIO_NUM_13;
const uint64_t GPIO_CTRL_PANEL_ENC_BTN_BIT_MASK = (1ULL << GPIO_CTRL_PANEL_ENC_BTN);

// gpio/pin definitions
//const gpio_num_t GPIO_BTN_UP = GPIO_NUM_4;
//const gpio_num_t GPIO_BTN_DOWN = GPIO_NUM_5;
//const gpio_num_t GPIO_BTN_SET = GPIO_NUM_13;
//const uint64_t GPIO_BTN_UP_DOWN_SET_BIT_MASK = ((1ULL << GPIO_BTN_UP) | (1ULL << GPIO_BTN_DOWN) | (1ULL << GPIO_BTN_SET));


pcnt_unit_handle_t ctrl_panel_enc_pcnt_unit = NULL;
//static QueueHandle_t ctrl_panel_enc_queue = NULL;
//
//// isr event handler for buttons (up/down)
//static void IRAM_ATTR ctrl_panel_enc_btn_event_handler(void* arg) {
//    uint32_t gpio_num = (uint32_t)arg;
//    xQueueSendFromISR(ctrl_panel_enc_queue, &gpio_num, NULL);
//}

//static bool example_pcnt_on_reach(pcnt_unit_handle_t unit, const pcnt_watch_event_data_t *edata, void *user_ctx)
//{
//    BaseType_t high_task_wakeup;
//    QueueHandle_t queue = (QueueHandle_t)user_ctx;
//    // send event data to queue, from this interrupt callback
//    xQueueSendFromISR(queue, &(edata->watch_point_value), &high_task_wakeup);
//    return (high_task_wakeup == pdTRUE);
//}
lv_group_t * g;

static void lv_tick_task(void *arg) {
    (void) arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}

#if defined CONFIG_USE_LV_TOUCH_CALIBRATION

// callback function when touch calibration is complete
void lv_tc_finish_cb(lv_event_t *event) {
    lv_obj_t *originalScreen = (lv_obj_t*)(event->user_data);
    lv_obj_t *tCScreen = lv_scr_act();
    if (event->code == LV_EVENT_READY) {
        lv_disp_load_scr(originalScreen);
        ui_init();
        lv_obj_del(tCScreen);
    } else {
        ESP_LOGE(TAG, "unexpected lv event code '%d' (expected '%d') after touch calibration", lv_event_get_code(event),
                 LV_EVENT_READY);
    }
}

// function to create the touch calibration screen and begin the calibration
static void start_touch_calibration() {
    lv_obj_t *activeScreen = lv_scr_act();
    lv_obj_t *tCScreen = lv_tc_screen_create();
    lv_obj_add_event_cb(tCScreen, lv_tc_finish_cb, LV_EVENT_READY, activeScreen);
    lv_disp_load_scr(tCScreen);
    lv_tc_screen_start(tCScreen);
}

#endif

bool ctrl_panel_enc_btn_pressed() {
    return gpio_get_level(GPIO_CTRL_PANEL_ENC_BTN) == 0;
}

void ctrl_panel_enc_lv_cb(struct _lv_indev_drv_t *drv, lv_indev_data_t*data){

    static int lastEncVal = 0;
    int currentEncVal;
    pcnt_unit_get_count(ctrl_panel_enc_pcnt_unit, &currentEncVal);
    int encDiff = currentEncVal-lastEncVal;
//    if(data->enc_diff != encDiff) {
//        ESP_LOGI(TAG, "encoder value: %d | last diff: %d, current diff: %d", currentEncVal, data->enc_diff, encDiff);
//    }
//    lv_obj_t * focused_obj = lv_group_get_focused(g);
//
//    if(focused_obj == ui_BootScreen) {
//        ESP_LOGI(TAG, "ui_BootScreen is focused");
//    }
//    if(focused_obj == ui_MainScreen) {
//        ESP_LOGI(TAG, "ui_MainScreen is focused");
//    }
//    if(focused_obj == ui_MenuScreen) {
//        ESP_LOGI(TAG, "ui_MenuScreen is focused");
//    }
//    if(focused_obj == ui_SettingsScreen) {
//        ESP_LOGI(TAG, "ui_SettingsScreen is focused");
//    }
//    if(focused_obj == ui_TimerScreen) {
//        ESP_LOGI(TAG, "ui_TimerScreen is focused");
//    }

    if(encDiff<0) {
      //  ESP_LOGI(TAG,"focused obj: %p", focused_obj);
        encDiff = -1;
    } else if(encDiff > 0) {
      //  ESP_LOGI(TAG,"focused obj: %p", focused_obj);
        encDiff = 1;
    } else {
        encDiff = 0;
    }
    data->enc_diff = (int16_t)encDiff;
    //data->key = LV_KEY_ENTER;
    if(ctrl_panel_enc_btn_pressed()) {
       // ESP_LOGI(TAG, "encoder btn pressed!");
        data->state = LV_INDEV_STATE_PR;
    } else{
        data->state = LV_INDEV_STATE_REL;
    }
    lastEncVal = currentEncVal;
  //  return false; /*No buffering now so no more data read*/
}

static void setupCtrlPanelEncoder() {
    // ----------------
    ESP_LOGI(TAG, "install pcnt unit");
    pcnt_unit_config_t unit_config = {
            .high_limit = EXAMPLE_PCNT_HIGH_LIMIT,
            .low_limit = EXAMPLE_PCNT_LOW_LIMIT,
    };
    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &ctrl_panel_enc_pcnt_unit));

    ESP_LOGI(TAG, "set glitch filter");
    pcnt_glitch_filter_config_t filter_config = {
            .max_glitch_ns = 1000,
    };
    ESP_ERROR_CHECK(pcnt_unit_set_glitch_filter(ctrl_panel_enc_pcnt_unit, &filter_config));

    ESP_LOGI(TAG, "install pcnt channels");
    pcnt_chan_config_t chan_a_config = {
            .edge_gpio_num = GPIO_CTRL_PANEL_ENC_A,
            .level_gpio_num = GPIO_CTRL_PANEL_ENC_B,
    };
    pcnt_channel_handle_t pcnt_chan_a = NULL;
    ESP_ERROR_CHECK(pcnt_new_channel(ctrl_panel_enc_pcnt_unit, &chan_a_config, &pcnt_chan_a));
    pcnt_chan_config_t chan_b_config = {
            .edge_gpio_num = GPIO_CTRL_PANEL_ENC_B,
            .level_gpio_num = GPIO_CTRL_PANEL_ENC_A,
    };
    pcnt_channel_handle_t pcnt_chan_b = NULL;
    ESP_ERROR_CHECK(pcnt_new_channel(ctrl_panel_enc_pcnt_unit, &chan_b_config, &pcnt_chan_b));

    ESP_LOGI(TAG, "set edge and level actions for pcnt channels");
    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_chan_a, PCNT_CHANNEL_EDGE_ACTION_DECREASE, PCNT_CHANNEL_EDGE_ACTION_INCREASE));
    ESP_ERROR_CHECK(pcnt_channel_set_level_action(pcnt_chan_a, PCNT_CHANNEL_LEVEL_ACTION_KEEP, PCNT_CHANNEL_LEVEL_ACTION_INVERSE));
    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_chan_b, PCNT_CHANNEL_EDGE_ACTION_INCREASE, PCNT_CHANNEL_EDGE_ACTION_DECREASE));
    ESP_ERROR_CHECK(pcnt_channel_set_level_action(pcnt_chan_b, PCNT_CHANNEL_LEVEL_ACTION_KEEP, PCNT_CHANNEL_LEVEL_ACTION_INVERSE));
//
//    ESP_LOGI(TAG, "add watch points and register callbacks");
//    int watch_points[] = {EXAMPLE_PCNT_LOW_LIMIT, -50, 0, 50, EXAMPLE_PCNT_HIGH_LIMIT};
//    for (size_t i = 0; i < sizeof(watch_points) / sizeof(watch_points[0]); i++) {
//        ESP_ERROR_CHECK(pcnt_unit_add_watch_point(ctrl_panel_enc_pcnt_unit, watch_points[i]));
//    }
//    pcnt_event_callbacks_t cbs = {
//            .on_reach = example_pcnt_on_reach,
//    };
//    ctrl_panel_enc_queue = xQueueCreate(10, sizeof(int));
//    ESP_ERROR_CHECK(pcnt_unit_register_event_callbacks(ctrl_panel_enc_pcnt_unit, &cbs, ctrl_panel_enc_queue));

    ESP_LOGI(TAG, "enable pcnt unit");
    ESP_ERROR_CHECK(pcnt_unit_enable(ctrl_panel_enc_pcnt_unit));
    ESP_LOGI(TAG, "clear pcnt unit");
    ESP_ERROR_CHECK(pcnt_unit_clear_count(ctrl_panel_enc_pcnt_unit));
    ESP_LOGI(TAG, "start pcnt unit");
    ESP_ERROR_CHECK(pcnt_unit_start(ctrl_panel_enc_pcnt_unit));

    ESP_LOGI(TAG, "configuring gpio buttons...");
    gpio_config_t gpio_btn_conf =  {
            .pin_bit_mask= GPIO_CTRL_PANEL_ENC_BTN_BIT_MASK,
            .mode = GPIO_MODE_INPUT,
            .pull_up_en = GPIO_PULLUP_ENABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_ANYEDGE
    };

    esp_err_t err = gpio_config(&gpio_btn_conf);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "error configuring gpio: %s", esp_err_to_name(err));
    }
    // ----------------

}
static void guiTask(void *pvParameter) {

    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t* buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    lv_color_t* buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_draw_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820         \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A    \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D     \
    || defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306

    /* Actual size in pixels, not bytes. */
    size_in_px *= 8;
#endif

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

#if defined CONFIG_DISPLAY_ORIENTATION_PORTRAIT || defined CONFIG_DISPLAY_ORIENTATION_PORTRAIT_INVERTED
    disp_drv.rotated = 1;
#endif

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
    // disable antialiasing when using monochrome display
    disp_drv.antialiasing = 0;
#endif

    // need to set resolution for LVGL 8x
    disp_drv.hor_res = CONFIG_LV_HOR_RES_MAX;
    disp_drv.ver_res = CONFIG_LV_VER_RES_MAX;

    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
#if CONFIG_USE_LV_TOUCH_CALIBRATION // if using LVGL Touch Calibration
    lv_tc_indev_drv_init(&indev_drv, touch_driver_read);
#ifndef CONFIG_USE_CUSTOM_LV_TC_COEFFICIENTS // if NOT using custom calibration coefficients
    lv_tc_register_coeff_save_cb(esp_nvs_tc_coeff_save_cb);
#endif
#else // if NOT using LVGL Touch Calibration
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
#endif
    lv_indev_drv_register(&indev_drv);
#endif


    lv_indev_drv_t indev_encoder_drv;
    lv_indev_drv_init(&indev_encoder_drv);
    indev_encoder_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_encoder_drv.read_cb = ctrl_panel_enc_lv_cb;
    indev_encoder_drv.long_press_time = 500;
    //lv_indev_t* indev_encoder = lv_indev_drv_register(&indev_encoder_drv);
    indev_encoder = lv_indev_drv_register(&indev_encoder_drv);
//    g = lv_group_create();
//    lv_group_set_default(g);
//    lv_indev_set_group(indev_encoder, g);

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
            .callback = &lv_tick_task,
            .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    /* SquareLine ui_init() */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    #if CONFIG_USE_CUSTOM_LV_TC_COEFFICIENTS == 0
    // esp_nvs_tc_coeff_erase(); // this can be used to erase the stored coeff data on nvs
    if (esp_nvs_tc_coeff_init()) {
        ui_init();
    } else {
        start_touch_calibration();
    }
#else
    lv_tc_load_coeff_from_config();
    ui_init();
#endif
#else
    ui_init();
#endif
//
//lv_group_add_obj(g, ui_MainScreen);
//    lv_group_add_obj(g, ui_rollerMenuScreenItems);

//    lv_group_add_obj(g, ui_rollerMenuScreenItems);
//   lv_obj_add_flag(ui_rollerMenuScreenItems, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
//   lv_obj_add_state(ui_rollerMenuScreenItems, LV_STATE_FOCUSED | LV_STATE_EDITED);
   // lv_event_send(ui_rollerMenuScreenItems, LV_EVENT_SHORT_CLICKED, NULL);
    //lv_event_send(ui_rollerMenuScreenItems, LV_EVENT_SHORT_CLICKED, NULL);
    //lv_group_focus_obj(ui_rollerMenuScreenItems);
   // lv_group_add_obj(g, ui_rollerMenuScreenItems);
   // lv_group_add_obj(g, ui_rollerMemoryScreenItems);
   // lv_group_add_obj(g, ui_rollerTimerScreenItems);
   // lv_group_add_obj(g, ui_rollerSettingsScreenItems);
   // lv_group_add_obj(g, ui_rollerTestRollerScreenItems);



    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}


/**********************
 *   APPLICATION MAIN
 **********************/
void app_main() {
    setupCtrlPanelEncoder();
    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    xTaskCreatePinnedToCore(guiTask, "gui", 4096*2, NULL, 0, NULL, 1);
}

// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: ElectricDeskControllerUI

#include "../ui.h"

void ui_BootScreen_screen_init(void)
{
    ui_BootScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BootScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_BootScreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_BootScreen, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_border_color(ui_BootScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BootScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BootScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_BootScreen, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblBootScreenAppTitle = lv_label_create(ui_BootScreen);
    lv_obj_set_width(ui_lblBootScreenAppTitle, 125);
    lv_obj_set_height(ui_lblBootScreenAppTitle, 35);
    lv_obj_set_x(ui_lblBootScreenAppTitle, 67);
    lv_obj_set_y(ui_lblBootScreenAppTitle, 30);
    lv_obj_set_align(ui_lblBootScreenAppTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblBootScreenAppTitle, "Electric Desk Controller");
    lv_obj_set_style_text_color(ui_lblBootScreenAppTitle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblBootScreenAppTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblBootScreenAppTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblBootScreenAppTitle, &ui_font_MontserratSemiBold14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_lblBootScreenAppTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_lblBootScreenAppTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_lblBootScreenAppTitle, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_lblBootScreenAppTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblBootScreenGitUrl = lv_label_create(ui_BootScreen);
    lv_obj_set_width(ui_lblBootScreenGitUrl, 128);
    lv_obj_set_height(ui_lblBootScreenGitUrl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblBootScreenGitUrl, 67);
    lv_obj_set_y(ui_lblBootScreenGitUrl, 30);
    lv_obj_set_align(ui_lblBootScreenGitUrl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblBootScreenGitUrl, "github.com/hiruna");
    lv_obj_set_style_text_color(ui_lblBootScreenGitUrl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblBootScreenGitUrl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblBootScreenGitUrl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblBootScreenGitUrl, &ui_font_MontserratSemiBold10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblBootScreenAppVer = lv_label_create(ui_BootScreen);
    lv_obj_set_height(ui_lblBootScreenAppVer, 15);
    lv_obj_set_width(ui_lblBootScreenAppVer, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_lblBootScreenAppVer, 67);
    lv_obj_set_y(ui_lblBootScreenAppVer, 30);
    lv_obj_set_align(ui_lblBootScreenAppVer, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblBootScreenAppVer, "v1.0");
    lv_label_set_recolor(ui_lblBootScreenAppVer, "true");
    lv_obj_set_style_text_color(ui_lblBootScreenAppVer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblBootScreenAppVer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblBootScreenAppVer, &ui_font_MontserratSemiBold10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_BootScreen, ui_event_BootScreen, LV_EVENT_ALL, NULL);

}

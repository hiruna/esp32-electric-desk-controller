// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: ElectricDeskControllerUI

#ifndef _ELECTRICDESKCONTROLLERUI_UI_H
#define _ELECTRICDESKCONTROLLERUI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_BootScreen
void ui_BootScreen_screen_init(void);
void ui_event_BootScreen(lv_event_t * e);
extern lv_obj_t * ui_BootScreen;
extern lv_obj_t * ui_lblBootScreenAppTitle;
extern lv_obj_t * ui_lblBootScreenGitUrl;
extern lv_obj_t * ui_lblBootScreenAppVer;
// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
void ui_event_MainScreen(lv_event_t * e);
extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_panelMainScreenHeader;
extern lv_obj_t * ui_panelMainScreenHeaderLeft;
extern lv_obj_t * ui_imgMainScreenHeaderTimer;
extern lv_obj_t * ui_lblMainScreenHeaderTimerText;
extern lv_obj_t * ui_panelMainScreenHeaderDivider;
extern lv_obj_t * ui_panelMainScreenHeaderRight;
extern lv_obj_t * ui_imgMainScreenHeaderLockStatus;
extern lv_obj_t * ui_imgMainScreenHeaderWifi;
extern lv_obj_t * ui_panelMainScreenMid;
extern lv_obj_t * ui_lblDeskHeightValue;
extern lv_obj_t * ui_lblDeskHeightUnits;
extern lv_obj_t * ui_panelMainScreenFooter;
extern lv_obj_t * ui_lblMainScreenFooterNotifText;
// SCREEN: ui_MenuScreen
void ui_MenuScreen_screen_init(void);
void ui_event_MenuScreen(lv_event_t * e);
extern lv_obj_t * ui_MenuScreen;
extern lv_obj_t * ui_panelMenuScreenHeader;
extern lv_obj_t * ui_Label1;
void ui_event_rollerMenuScreenItems(lv_event_t * e);
extern lv_obj_t * ui_rollerMenuScreenItems;
// SCREEN: ui_MemoryScreen
void ui_MemoryScreen_screen_init(void);
extern lv_obj_t * ui_MemoryScreen;
extern lv_obj_t * ui_panelMemoryScreenHeader;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_rollerMemoryScreenItems;
// SCREEN: ui_TimerScreen
void ui_TimerScreen_screen_init(void);
extern lv_obj_t * ui_TimerScreen;
extern lv_obj_t * ui_panelTimerScreenHeader;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_rollerTimerScreenItems;
// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
extern lv_obj_t * ui_SettingsScreen;
extern lv_obj_t * ui_panelSettingsScreenHeader;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_rollerSettingsScreenItems;
void ui_event____initial_actions0(lv_event_t * e);
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_wifi_solid_png);    // assets/wifi_solid.png

LV_FONT_DECLARE(ui_font_FontAwesomeRegular12);
LV_FONT_DECLARE(ui_font_FontAwesomeRegular24);
LV_FONT_DECLARE(ui_font_MontserratSemiBold10);
LV_FONT_DECLARE(ui_font_MontserratSemiBold14);
LV_FONT_DECLARE(ui_font_MontserratSemiBold24);
LV_FONT_DECLARE(ui_font_MontserratSemiBold30);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

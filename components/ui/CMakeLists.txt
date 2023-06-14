SET(SOURCES screens/ui_BootScreen.c
    screens/ui_MainScreen.c
    screens/ui_MenuScreen.c
    screens/ui_MemoryScreen.c
    screens/ui_TimerScreen.c
    screens/ui_SettingsScreen.c
    ui.c
ui_events.c
    ui_helpers.c
    images/ui_img_stopwatch_png.c
    images/ui_img_clock_png.c
    images/ui_img_wifi_solid_png.c
    images/ui_img_sort_up_png.c
    images/ui_img_sort_down_png.c
    images/ui_img_empty_12x12_png.c
    fonts/ui_font_FontAwesomeRegular12.c
    fonts/ui_font_FontAwesomeRegular24.c
    fonts/ui_font_MontserratSemiBold10.c
    fonts/ui_font_MontserratSemiBold14.c
    fonts/ui_font_MontserratSemiBold24.c
    fonts/ui_font_MontserratSemiBold30.c)

idf_component_register(SRCS ${SOURCES} REQUIRES lvgl)

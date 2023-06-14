#!/usr/bin/env bash

sed -i 's/add_library.*/idf_component_register(SRCS ${SOURCES} REQUIRES lvgl)/g' CMakeLists.txt
# fix for ui_events.c
sed -i '/^.*ui.c.*/a ui_events.c' CMakeLists.txt
# fixes for monochrome
sed -i 's/#if LV_COLOR_DEPTH != 8/#if LV_COLOR_DEPTH != 1/g' ui.c
sed -i 's/.*false, LV_FONT_DEFAULT);//g' ui.c
sed -i 's/.*lv_theme_.*/lv_theme_t * theme = lv_theme_mono_init(dispp, false, LV_FONT_DEFAULT);/g' ui.c
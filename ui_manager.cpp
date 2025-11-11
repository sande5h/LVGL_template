#include "ui_manager.h"
#include "battery_screen.h"
#include "weather_screen.h"

static lv_obj_t *current_screen = NULL;

void ui_manager_init() {
    // optional initialization if needed
}

void switch_to(lv_obj_t *new_screen) {
    if (current_screen != NULL)
        lv_obj_del(current_screen);

    current_screen = new_screen;
    lv_scr_load(current_screen);
}

void ui_manager_show_menu() {
    lv_obj_t *menu = lv_obj_create(NULL);
    lv_obj_t *btn_battery = lv_btn_create(menu);
    lv_obj_align(btn_battery, LV_ALIGN_CENTER, 0, -40);
    lv_obj_t *lbl1 = lv_label_create(btn_battery);
    lv_label_set_text(lbl1, "Battery");

    lv_obj_t *btn_weather = lv_btn_create(menu);
    lv_obj_align(btn_weather, LV_ALIGN_CENTER, 0, 40);
    lv_obj_t *lbl2 = lv_label_create(btn_weather);
    lv_label_set_text(lbl2, "Weather");

    lv_obj_add_event_cb(btn_battery, [](lv_event_t *e) {
        ui_manager_show_battery();
    }, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(btn_weather, [](lv_event_t *e) {
        ui_manager_show_weather();
    }, LV_EVENT_CLICKED, NULL);

    switch_to(menu);
}

void ui_manager_show_battery() {
    switch_to(battery_screen_create());
}

void ui_manager_show_weather() {
    switch_to(weather_screen_create());
}

#include "battery_screen.h"
#include "ui_manager.h"

lv_obj_t* battery_screen_create() {
    lv_obj_t *scr = lv_obj_create(NULL);
    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "Battery Status: 90%");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *btn_back = lv_btn_create(scr);
    lv_obj_align(btn_back, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_t *lbl = lv_label_create(btn_back);
    lv_label_set_text(lbl, "Menu");

    lv_obj_add_event_cb(btn_back, [](lv_event_t *e) {
        ui_manager_show_menu();
    }, LV_EVENT_CLICKED, NULL);

    return scr;
}

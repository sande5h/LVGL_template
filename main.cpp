#include "lvgl.h"
#include "ui_manager.h"

int main() {
    lv_init();
    // your display and input driver initialization here...

    ui_manager_init();    
    ui_manager_show_menu(); 

    while (1) {
        lv_timer_handler();
        delay(5);
    }
    return 0;
}

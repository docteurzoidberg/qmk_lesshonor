#include "drzoid.h"

void my_custom_function(void) {

}

#ifdef RGBLIGHT_ENABLE
    void drz_rgblight_set_hsv(uint8_t h, uint8_t s, uint8_t v) {
        rgblight_sethsv_noeeprom_old(h,s,v);
    }

    void drz_rgblight_set_cyan() {
        rgblight_sethsv_noeeprom_old(HSV_CYAN);
    }

    void drz_rgblight_set_orange() {
        rgblight_sethsv_noeeprom_old(HSV_ORANGE);
    }

    void drz_rgblight_set_red() {
        rgblight_sethsv_noeeprom_old(HSV_RED);
    }

    void drz_rgblight_set_yellow() {
        rgblight_sethsv_noeeprom_old(HSV_YELLOW);
    }

    void drz_rgblight_set_green() {
        rgblight_sethsv_noeeprom_old(HSV_GREEN);
    }
#endif

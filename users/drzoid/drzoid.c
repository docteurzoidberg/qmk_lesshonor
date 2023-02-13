#include "drzoid.h"

void my_custom_function(void) {

}

#define HSV_AZURE       132, 102, 255
#define HSV_BLACK         0,   0,   0
#define HSV_BLUE        170, 255, 255
#define HSV_CHARTREUSE   64, 255, 255
#define HSV_CORAL        11, 176, 255
#define HSV_CYAN        128, 255, 255
#define HSV_GOLD         36, 255, 255
#define HSV_GOLDENROD    30, 218, 218
#define HSV_GREEN        85, 255, 255
#define HSV_MAGENTA     213, 255, 255
#define HSV_ORANGE       21, 255, 255
#define HSV_PINK        234, 128, 255
#define HSV_PURPLE      191, 255, 255
#define HSV_RED           0, 255, 255
#define HSV_SPRINGGREEN 106, 255, 255
#define HSV_TEAL        128, 255, 128
#define HSV_TURQUOISE   123,  90, 112
#define HSV_WHITE         0,   0, 255
#define HSV_YELLOW       43, 255, 255
#define HSV_OFF         HSV_BLACK



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

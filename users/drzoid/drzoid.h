#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void my_custom_function(void);
#ifdef RGBLIGHT_ENABLE
    void drz_rgblight_set_cyan(void);
    void drz_rgblight_set_orange(void);
    void drz_rgblight_set_red(void);
    void drz_rgblight_set_yellow(void);
    void drz_rgblight_set_green(void);
    void drz_rgblight_set_hsv(uint8_t h, uint8_t s, uint8_t v);
#endif
#endif

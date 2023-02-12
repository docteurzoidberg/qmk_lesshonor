#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void my_custom_function(void);

#ifdef RGBLIGHT_ENABLE
#define rgblight_set_blue        rgblight_sethsv (0xFF,  0xFF, 0xEE);
#define rgblight_set_red         rgblight_sethsv (0x00,  0xFF, 0xEE);
#define rgblight_set_green       rgblight_sethsv (0x78,  0xFF, 0xEE);
#define rgblight_set_orange      rgblight_sethsv (0x1E,  0xFF, 0xEE);
#define rgblight_set_teal        rgblight_sethsv (0xC3,  0xFF, 0xEE);
#define rgblight_set_magenta     rgblight_sethsv (0x12C, 0xFF, 0xEE);
#define rgblight_set_yellow      rgblight_sethsv (0x3C,  0xFF, 0xEE);
#define rgblight_set_purple      rgblight_sethsv (0x10E, 0xFF, 0xEE);
#define rgblight_set_white       rgblight_sethsv (0x00,  0x00, 0xEE);

void rgblight_setrgb_cyan(void);
void rgblight_setrgb_orange(void);
void rgblight_setrgb_red(void);
void rgblight_setrgb_yellow(void);
void rgblight_setrgb_green(void);
#endif
#endif

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum userspace_custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
  L2,
  L3,
  DRZ_LOCK,
  DRZ_SWAP_HANDS=SH_MON,
  DRZ_LEFT_SHIFT_CAPSLOCK,
  DRZ_RIGHT_SHIFT_CAPSLOCK,
  DRZ_ACCENTS_TAPDANCE,
  DRZ_EMOJIS_TAPDANCE,
  DRZ_LPUP,
  DRZ_LPDN,
  DRZ_LPRP,
  DRZ_LPTG,
  DRZ_LPON,
  DRZ_LPOFF,
  NEW_SAFE_RANGE // use "NEWPLACEHOLDER for keymap specific codes
};

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

#pragma once

#include QMK_KEYBOARD_H

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
  DRZ_MACRO_COMMENT_START,
  DRZ_MACRO_COMMENT_END,
  DRZ_MACRO_TEST_SENDSTRING,
  DRZ_MACRO_EVE,
  DRZ_SECRET_1,                             // test1
  DRZ_SECRET_2,                             // test2
  DRZ_SECRET_3,                             // test3
  DRZ_SECRET_4,                             // test4
  DRZ_SECRET_5,                             // test5
  DRZ_LPUP,
  DRZ_LPDN,
  DRZ_LPRP,
  DRZ_LPTG,
  DRZ_LPON,
  DRZ_LPOFF,
  NEW_SAFE_RANGE // use "NEWPLACEHOLDER for keymap specific codes
};

#define _QW 0
#define _SH 1
#define _L2 2
#define _L3 3
#define _FN 4
#define _MC 5
#define _M2 6
#define _M3 7
#define _MF 8

layer_state_t _state;
extern bool swap_hands;
uint8_t _layer_lock;

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

//Unicode chars
#ifdef UNICODE_ENABLE
  #define DRZ_UC_STAR     KC_NO
  #define DRZ_UC_SQUARE   KC_NO
  #define DRZ_UC_CUBE     KC_NO
#else
  #define DRZ_UC_STAR     KC_NO
  #define DRZ_UC_SQUARE   KC_NO
  #define DRZ_UC_CUBE     KC_NO
#endif

//uni-sized keycodes for keymap uses
#define DRZ_ENT  KC_ENTER
#define DRZ_BSP  KC_BACKSPACE
#define DRZ_SPA  KC_SPACE
#define DRZ_RST  QK_BOOTLOADER
#define DRZ_UST  DRZ_UC_STAR
#define DRZ_USQ  DRZ_UC_SQUARE
#define DRZ_UCU  DRZ_UC_CUBE
#define DRZ_LCK  DRZ_LOCK
#define DRZ__ST  LSFT(KC_TAB)
#define DRZ__SH  SH_TT
#define DRZ__LS  KC_LEFT_SHIFT
#define DRZ__RS  KC_RIGHT_SHIFT
#define DRZ__AC  DRZ_ACCENTS_TAPDANCE
#define DRZ__EM  DRZ_EMOJIS_TAPDANCE
#define DRZ__CA  LCTL(KC_LEFT_ALT)
#define DRZ__CS  LCTL(KC_LEFT_SHIFT)
#define DRZ_MCS  DRZ_MACRO_COMMENT_START
#define DRZ_MCE  DRZ_MACRO_COMMENT_END
#define DRZ_TST  DRZ_MACRO_TEST_SENDSTRING
#define DRZ_EVE  DRZ_MACRO_EVE
#define DRZ_ATB  LALT(KC_TAB)

//Qwerty single num keys
#define DRZ___1   KC_1
#define DRZ___2   KC_2
#define DRZ___3   KC_3
#define DRZ___4   KC_4
#define DRZ___5   KC_5
#define DRZ___6   KC_6
#define DRZ___7   KC_7
#define DRZ___8   KC_8
#define DRZ___9   KC_9
#define DRZ___0   KC_0

//Qwerty single alpha keys
#define DRZ___Q   KC_Q
#define DRZ___W   KC_W
#define DRZ___E   KC_E
#define DRZ___R   KC_R
#define DRZ___T   KC_T
#define DRZ___Y   KC_Y
#define DRZ___U   KC_U
#define DRZ___I   KC_I
#define DRZ___O   KC_O
#define DRZ___P   KC_P
#define DRZ___A   KC_A
#define DRZ___S   KC_S
#define DRZ___D   KC_D
#define DRZ___F   KC_F
#define DRZ___G   KC_G
#define DRZ___H   KC_H
#define DRZ___J   KC_J
#define DRZ___K   KC_K
#define DRZ___L   KC_L
#define DRZ___Z   KC_Z
#define DRZ___X   KC_X
#define DRZ___C   KC_C
#define DRZ___V   KC_V
#define DRZ___B   KC_B
#define DRZ___N   KC_N
#define DRZ___M   KC_M

#define DRZ_MNS KC_MINS
#define DRZ_PLS KC_PLUS
#define DRZ_EQU KC_EQL
#define DRZ_UDS KC_UNDS
#define DRZ_SLA KC_SLASH

#define DRZ_DLR LSFT(KC_4)
#define DRZ_DOT KC_DOT
#define DRZ_COM LSFT(KC_LABK)

#define DRZ_SUP KC_RABK       //  > (superior)
#define DRZ_LES KC_LABK       //  < (inferior)
#define DRZ_SCL KC_SCLN
#define DRZ_CLN KC_COLN
#define DRZ_TIL KC_TILD
#define DRZ_SBL KC_LBRC
#define DRZ_SBR KC_RBRC
#define DRZ_CBL KC_LCBR
#define DRZ_CBR KC_RCBR
#define DRZ_PIP KC_PIPE       //  | (pipe)
#define DRZ_INT KC_QUES       //  ? (interrogation mark)
#define DRZ_SQT KC_GRV        //  ` (special quote ?)
#define DRZ_ASL KC_BSLS       //  \ (antislash)
#define DRZ_AST KC_ASTR
#define DRZ_EXC KC_EXLM
#define DRZ_LPR KC_LPRN
#define DRZ_RPR KC_RPRN
#define DRZ_APS KC_QUOT       // '
#define DRZ_QOT KC_DQT        // "

#define DRZ_PND RALT(LSFT(KC_4))
#define DRZ_DEG RALT(LSFT(KC_SCLN))
#define DRZ_EUR RALT(KC_5)

#ifdef DRZ_SECRETS_ENABLED
    bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
#endif

#ifdef DRZ_LONGPRESS_ENABLED
    #include "process_longpress.h"
#endif

#ifdef DRZ_RGBLIGHT_ENABLED
    #include "rgb_light.h"
#endif

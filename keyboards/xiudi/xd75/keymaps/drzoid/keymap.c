#ifndef XD75_DRZ_LAYOUT_MIRRORED

/*
Drzoid's mirrored 5x15 ortho layout
This layout:
  -> http://www.keyboard-layout-editor.com/#/gists/a59dd1a00a45c5dcd38d9e765675dd41
*/

#include QMK_KEYBOARD_H

#include "drzoid.h"
#include "quantum.h"

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

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

uint8_t _layer_lock=_QW;

enum custom_macros {
  DRZ_MACRO_COMMENT_START,
  DRZ_MACRO_COMMENT_END,
  DRZ_MACRO_TEST_SENDSTRING,
  DRZ_MACRO_EVE
};

//static bool isAltSetBySpecialTab = false;

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{14, 0}, {13, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {7, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {1, 0}, {0, 0}},
  {{14, 1}, {13, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1}, {12, 1}, {7, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {1, 1}, {0, 1}},
  {{14, 2}, {13, 2}, {8, 2}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {7, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {1, 2}, {0, 2}},
  {{14, 3}, {13, 3}, {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {7, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {1, 3}, {0, 3}},
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//
  //DEFAULT LAYER
  //KLE url: http://www.keyboard-layout-editor.com/#/gists/3aede80592346f947cbc1eb91574d1c7

//        [LOCK+] [ESC  ] [1!/¹/] [2@/² ] [3#/³ ] [4$/£/] [5%/€ ] [Macro] [6^/¼ ] [7&/½ ] [8*/¾ ] [9(/‘ ] [0)/’ ] [ESC  ] [LOCK+]
//        [FN   ] [OS   ] [Q/Ä/ä] [W/Å/å] [E/É/é] [R/®  ] [T/Þ/Þ] [M1   ] [Y/Ü/ü] [U/Ú/ú] [I/Í/í] [O/Ó/ó] [P/Ó/ó] [OS   ] [FN   ]
//        [L3   ] [LALT ] [A/Á/á] [S/§/ß] [D/Ð/ð] [F    ] [G    ] [M2   ] [H    ] [J    ] [K    ] [L/Ø/ø] [:;   ] [RALT ] [L3   ]
//        [L2   ] [/CAPS] [Z/Æ/æ] [X    ] [C/¢/©] [V    ] [B    ] [M3   ] [N/Ñ/ñ] [M/µ  ] [\ | /] [↑    ] [.,   ] [/CAPS] [L2   ]
//        [SWAP ] [CTRL ] [/Acce] [/Smil] [MENU ] [TAB  ] [SPACE] [ENTER] [SPACE] [BKSPC] [←    ] [↓    ] [→    ] [RCTRL] [SWAP ]
//

  [_QW] =
    LAYOUT_ortho_5x15(
      DRZ_LCK,  KC_ESC,   DRZ___1,  DRZ___2,  DRZ___3,  DRZ___4,  DRZ___5,  TO(_MC),  DRZ___6,  DRZ___7,  DRZ___8,  DRZ___9,  DRZ___0,  KC_ESC,   DRZ_LCK,
      MO(_FN),  KC_LGUI,  DRZ___Q,  DRZ___W,  DRZ___E,  DRZ___R,  DRZ___T,  XXXXXXX,  DRZ___Y,  DRZ___U,  DRZ___I,  DRZ___O,  DRZ___P,  KC_RGUI,  MO(_FN),
      MO(_L3),  KC_LALT,  DRZ___A,  DRZ___S,  DRZ___D,  DRZ___F,  DRZ___G,  XXXXXXX,  DRZ___H,  DRZ___J,  DRZ___K,  DRZ___L,  DRZ_CLN,  KC_RALT,  MO(_L3),
      MO(_L2),  DRZ__LS,  DRZ___Z,  DRZ___X,  DRZ___C,  DRZ___V,  DRZ___B,  XXXXXXX,  DRZ___N,  DRZ___M,  DRZ_SLA,  KC_UP,    DRZ_DOT,  DRZ__RS,  MO(_L2),
      DRZ__SH,  KC_LCTL,  KC_LEAD,  KC_GRV,   KC_MENU,  KC_TAB,   DRZ_SPA,  DRZ_ENT,  DRZ_SPA,  DRZ_BSP,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_RCTL,  DRZ__SH
    ),


  //FN LAYER
  //KLE url: http://www.keyboard-layout-editor.com/#/gists/ea5fd62e5090bfd1ace06bb00ebc35b5
  [_FN] =
    LAYOUT_ortho_5x15(
      _______,  KC_MUTE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    DRZ_RST,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_MUTE,  _______,
      _______,  XXXXXXX,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   XXXXXXX,  KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   XXXXXXX,  _______,
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
      _______,  XXXXXXX,  KC_PSCR,  KC_PAUS,  KC_CALC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BL_OFF,   BL_ON,    BL_DEC,   RGB_HUI,  BL_INC,   XXXXXXX,  _______,
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_SAI,  RGB_HUD,  RGB_SAD,  XXXXXXX,  _______
    ),

  //LAYER 2
  //KLE url: http://www.keyboard-layout-editor.com/#/gists/873f4eb3c290906364daf000cb132b69
  [_L2] =
    LAYOUT_ortho_5x15(
      _______,  _______,  DRZ_TIL,  XXXXXXX,  DRZ_APS,  DRZ_QOT,  DRZ_PLS,  _______,  DRZ_MNS,  DRZ_SQT,  DRZ_UDS,  DRZ_UDS,  DRZ_EQU,  _______,  _______,
      _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_ASL,  DRZ_SBL,  _______,  DRZ_SBR,  DRZ_SLA,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,
      _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_LES,  DRZ_LPR,  _______,  DRZ_RPR,  DRZ_SUP,  XXXXXXX,  XXXXXXX,  DRZ_EXC,  _______,  _______,
      _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_MCS,  DRZ_CBL,  _______,  DRZ_CBR,  DRZ_MCE,  DRZ_PIP,  KC_PGUP,  DRZ_INT,  _______,  _______,
      _______,  DRZ__CA,  _______,  _______,  _______,  DRZ__ST,  _______,  _______,  _______,  KC_DEL,   KC_HOME,  KC_PGDN,  KC_END,   DRZ__CA,  _______
    ),

  //LAYER 3
  //KLE url: http://www.keyboard-layout-editor.com/#/gists/6ee8724672840abd6863985fa9fe7014
  [_L3] =
    LAYOUT_ortho_5x15(
      _______,  _______,  XXXXXXX,  DRZ_USQ,  DRZ_UST,  XXXXXXX, XXXXXXX,   _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_MNS,  _______,  _______,
      _______,  _______,  XXXXXXX,  XXXXXXX,  DRZ_EUR,  XXXXXXX, DRZ_ASL,   _______,  DRZ_SLA,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_PLS,  _______,  _______,
      _______,  _______,  XXXXXXX,  DRZ_DLR,  DRZ_DEG,  XXXXXXX, DRZ_LES,   _______,  DRZ_SUP,  XXXXXXX,  XXXXXXX,  DRZ_PND,  DRZ_AST,  _______,  _______,
      _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, DRZ_MCS,   _______,  DRZ_MCE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ_SLA,  _______,  _______,
      _______,  DRZ__CS,  _______,  _______,  _______,  DRZ_ATB, _______,   _______,  _______,  _______,  _______,  _______,  _______,  DRZ__CS,  _______
    ),

  //MINECRAFT/GAME LAYER
  //KLE url: http://www.keyboard-layout-editor.com/#/gists/
  [_MC] =
    LAYOUT_ortho_5x15(
      TO(_QW),  KC_ESC,   DRZ___1,  DRZ___2,  DRZ___3,  DRZ___4,  DRZ___5,  TO(_QW),  DRZ___6,  DRZ___7,  DRZ___8,  DRZ___9,  DRZ___0,  KC_ESC,   TO(_QW),
      MO(_MF),  KC_LGUI,  XXXXXXX,  DRZ___W,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RGUI,  MO(_MF),
      MO(_L3),  KC_LALT,  DRZ___A,  DRZ___S,  DRZ___D,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RALT,  MO(_M3),
      MO(_L2),  DRZ__LS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DRZ__RS,  MO(_M2),
      DRZ__SH,  KC_LCTL,  KC_LEAD,  DRZ__EM,  KC_MENU,  KC_TAB,   DRZ_SPA,  DRZ_ENT,  DRZ_SPA,  DRZ_BSP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCTL,  DRZ__SH
    ),
  [_M2] =
    LAYOUT_ortho_5x15(
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
  [_M3] =
    LAYOUT_ortho_5x15(
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
  [_MF] =
    LAYOUT_ortho_5x15(
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )
};

void matrix_init_user(void) {
  #ifdef DRZ_USE_UNICODE
    set_unicode_input_mode(UNICODE_MODE_WINDOWS);
  #endif
}

LEADER_EXTERNS();

void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_L){
      register_code(KC_RGUI);
      TAP_ONCE(KC_L);
      unregister_code(KC_RGUI);
    }

    //è
    SEQ_TWO_KEYS (KC_E, KC_G) {
      TAP_ONCE (KC_GRAVE); TAP_ONCE (KC_E);
    }

    //é
    SEQ_TWO_KEYS (KC_E, KC_A) {
      register_code (KC_RALT); TAP_ONCE (KC_E); unregister_code (KC_RALT);
    }

    //à
    SEQ_TWO_KEYS (KC_A, KC_G) {
      TAP_ONCE (KC_GRAVE); TAP_ONCE (KC_A);
    }
    //á
    SEQ_TWO_KEYS (KC_A, KC_A) {
      TAP_ONCE (KC_QUOTE); TAP_ONCE (KC_A);
    }
    //â
    SEQ_TWO_KEYS (KC_A, KC_C) {
      register_code (KC_RSFT); TAP_ONCE (KC_6); unregister_code (KC_RSFT); TAP_ONCE (KC_A);
    }

    //ê
    SEQ_TWO_KEYS (KC_E, KC_C) {
      register_code (KC_RSFT); TAP_ONCE (KC_6); unregister_code (KC_RSFT); TAP_ONCE (KC_E);
    }

    //¨e
    SEQ_TWO_KEYS (KC_E, KC_T) {
      register_code (KC_RALT); register_code (KC_RSFT); TAP_ONCE (KC_QUOTE); unregister_code (KC_RSFT); unregister_code (KC_RALT); TAP_ONCE (KC_E);
    }

    SEQ_TWO_KEYS (KC_U, KC_L) {
      set_unicode_input_mode(UNICODE_MODE_LINUX);
    }

    SEQ_TWO_KEYS (KC_U, KC_W) {
      set_unicode_input_mode(UNICODE_MODE_WINDOWS);
    }

    SEQ_TWO_KEYS (KC_S, KC_S) {
      // ¯\_(ツ)_/¯
      unicode_input_start(); register_hex(0xaf); unicode_input_finish();
      register_code (KC_LALT);
      register_code (KC_LCTL);
      TAP_ONCE (KC_MINS);
      unregister_code (KC_LCTL);
      unregister_code (KC_LALT);

      register_code (KC_RSFT); TAP_ONCE (KC_8); unregister_code (KC_RSFT);
      unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
      register_code (KC_RSFT); TAP_ONCE (KC_9); TAP_ONCE(KC_7); unregister_code (KC_RSFT);
      unicode_input_start (); register_hex(0xaf); unicode_input_finish();
    }

    SEQ_TWO_KEYS (KC_S, KC_F) {
      // 凸(ツ)凸
      unicode_input_start(); register_hex(0x51F8); unicode_input_finish();
      register_code (KC_RSFT); TAP_ONCE (KC_8); unregister_code (KC_RSFT);
      unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
      register_code (KC_RSFT); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
      unicode_input_start (); register_hex(0x51F8); unicode_input_finish();
    }

    SEQ_TWO_KEYS (KC_S, KC_L) {
      // λ
      unicode_input_start();
      register_hex(0x03bb);
      unicode_input_finish();
    }
    };
};

/*\ ------------------------------------------------------*/
//  MACRO ACTIONS
//  - Comment start:  / *
//  - Comment end:    * /
/*\-------------------------------------------------------*/
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {

    //->  * /
    case DRZ_MACRO_COMMENT_START:
      if(IS_PRESSED(record->event)) {
        return MACRO(T(KC_KP_SLASH), T(KC_KP_ASTERISK), END);
      }
    break;

    //->  / *
    case DRZ_MACRO_COMMENT_END:
      if(IS_PRESSED(record->event)) {
        return MACRO(T(KC_KP_ASTERISK), T(KC_KP_SLASH), KC_END);
      }
    break;

    case DRZ_MACRO_EVE:
      if(IS_PRESSED(record->event)) {
        return MACRO(D(KC_LEFT_CTRL), T(KC_UP), U(KC_LEFT_CTRL), T(KC_ENTER), KC_END);
      }
    break;

    case DRZ_MACRO_TEST_SENDSTRING:
      if(IS_PRESSED(record->event)) {
        SEND_STRING("1234567890!@#$%^&*()qwertyuiopQWERTYUIOPasdfghjklASDFGHJKL:;zxcvbnmZXCVBNM/\\|.,~+-' \"`_[]<>{}|?");
        return false;
      }
    break;
	}
	return MACRO_NONE;
}
*/

void press_key_with_level_mods(uint16_t key) {
  const uint8_t interesting_mods = MOD_BIT(KC_LEFT_SHIFT) | MOD_BIT(KC_RIGHT_SHIFT) | MOD_BIT(KC_RIGHT_ALT);

  // Save the state
  const uint8_t real_mods = get_mods();
  const uint8_t weak_mods = get_weak_mods();
  //const uint8_t macro_mods = get_macro_mods();

  uint8_t target_mods = (key >> 8) & (QK_MODS_MAX >> 8);

  // The 5th bit indicates that it's a right hand mod,
  // which needs some fixup
  if (target_mods & 0x10) {
    target_mods &= 0xF;
    target_mods <<= 4;
  }

  // Clear the mods that we are potentially going to modify,
  del_mods(interesting_mods);
  del_weak_mods(interesting_mods);
  //del_macro_mods(interesting_mods);

  // Enable the mods that we need
  add_mods(target_mods & interesting_mods);

  // Press and release the key
  register_code(key & 0xFF);
  unregister_code(key & 0xFF);

  // Restore the previous state
  set_mods(real_mods);
  set_weak_mods(weak_mods);
  //set_macro_mods(macro_mods);
  send_keyboard_report();
}

bool override_key(keyrecord_t* record, uint16_t normal, uint16_t shifted) {
  const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);
  // Todo, should maybe also check at least the weak mods
  uint8_t current_mods = get_mods();
  if (record->event.pressed) {
    // Todo share this code with send keyboard report
    #ifndef NO_ACTION_ONESHOT
      if (get_oneshot_mods()) {
        #if (defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0))
          if (has_oneshot_mods_timed_out()) {
              dprintf("Oneshot: timeout\n");
              clear_oneshot_mods();
          }
        #endif
        current_mods |= get_oneshot_mods();
        clear_oneshot_mods();
      }
    #endif
    bool shift_pressed = current_mods & shift;
    const uint16_t target = shift_pressed ? shifted : normal;
    uint8_t keycode = target & 0xFF;
    if (keycode == KC_NO) {
        return false;
    }
    press_key_with_level_mods(target);
  }
  return false;
}

static bool wake_dead_key(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        register_code16(keycode);
        unregister_code16(keycode);
        register_code16(KC_SPACE);
        unregister_code16(KC_SPACE);
        send_keyboard_report();
        return false;
    }
    // Let QMK handle onshots
    return true;
}

/*\ ------------------------------------------------------*/
//  LAYER CHANGE ACTIONS
//  - L2, L3, and FN layers to RGB underglow mapping
/*\-------------------------------------------------------*/
layer_state_t layer_state_set_user(layer_state_t state) {
    _state=state;

    //Store current value to put back after
    uint16_t h = rgblight_get_hue();
    uint8_t s = rgblight_get_sat();
    uint8_t v = 200;//rgblight_get_val();

    //Set layer rgb color or reset to original value
    switch (biton32(state)) {
      case _MF:
      case _FN:
          drz_rgblight_set_red();
          break;
      case _M3:
      case _L3:
          drz_rgblight_set_orange();
          break;
      case _M2:
      case _L2:
          drz_rgblight_set_yellow();
          break;
      case _MC:
          drz_rgblight_set_green();
          break;
      case _QW:
      default:
          //Put back to original value
          //rgblight_sethsv(h, s, v);
           drz_rgblight_set_hsv(h,s,v); //fix new qmk 02/2023
          break;
    }

  return state;
}

bool process_overides(uint16_t keycode, keyrecord_t *record) {

  bool returnValue = true;

  switch(keycode) {
    case DRZ_SLA:
      returnValue = override_key(record, DRZ_SLA, KC_BACKSLASH);
      break;
    case DRZ_CLN:
      returnValue = override_key(record, DRZ_CLN, KC_SEMICOLON);
      break;
    case DRZ_DOT:
      returnValue = override_key(record, DRZ_DOT, KC_COMMA);
      break;
    case DRZ_APS:
      returnValue = wake_dead_key(KC_QUOT, record);
      break;
    case DRZ_QOT:
      returnValue = wake_dead_key(KC_DQT, record);
      break;
    case DRZ_SQT:
      returnValue = wake_dead_key(KC_GRV, record);
      break;
  }

  return returnValue;
}

bool process_rgb_user(const uint16_t keycode, const keyrecord_t *record) {
  //bool returnValue = true;
  //uint16_t h = rgblight_get_hue();
  //uint8_t s = rgblight_get_sat();
  //uint8_t v = rgblight_get_val();
  if(swap_hands) {
  }

  if(IS_PRESSED(record->event)) {
    switch(keycode) {
      case TO(_MF):
      case TO(_FN):
      case TO(_L2):
      case TO(_L3):
      case TO(_QW):
      case TO(_MC):
      case TO(_M2):
      case TO(_M3):
      case MO(_MF):
      case MO(_FN):
      case MO(_L2):
      case MO(_L3):
      case MO(_QW):
      case MO(_MC):
      case MO(_M2):
      case MO(_M3):
        break;
      case DRZ__SH:
        drz_rgblight_set_cyan();
        break;
      default:
        rgblight_setrgb(64,64,64);
        break;
    }
  } else if(IS_RELEASED(record->event)) {
    layer_state_set_user(_state);
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool returnValue = true;

  //TODO: process macros...

  #ifdef LONGPRESS_ENABLE
    if(!process_longpress(keycode, record)) {
      return false;
    }
  #endif

  if(!process_overides(keycode, record)) {
    returnValue = false;
  }

  if(!process_rgb_user(keycode, record)) {
    returnValue = false;
  }

  return returnValue;
}

#endif

#include "drzoid.h"

uint8_t _layer_lock=_QW;

void matrix_init_user(void) {
  #ifdef UNICODE_ENABLE
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

    #ifdef UNICODE_ENABLE
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
    #endif
    };
};

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

layer_state_t layer_state_set_user(layer_state_t state) {
  _state=state;

  #ifdef DRZ_RGBLIGHT_ENABLED

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
  #endif
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
        #ifdef DRZ_RGBLIGHT_ENABLED
          drz_rgblight_set_cyan();
        #endif
        break;
      default:
        #ifdef DRZ_RGBLIGHT_ENABLED
          rgblight_setrgb(64,64,64);
        #endif
        break;
    }
  } else if(IS_RELEASED(record->event)) {
    layer_state_set_user(_state);
  }

  return true;
}

bool process_macros_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //->  * /
    case DRZ_MACRO_COMMENT_START:
      if(IS_PRESSED(record->event)) {
        //return MACRO(T(KC_KP_SLASH), T(KC_KP_ASTERISK), END);
        tap_code(KC_KP_SLASH);
        tap_code(KC_KP_ASTERISK);
        return false;
      }
    break;
    //->  / *
    case DRZ_MACRO_COMMENT_END:
      if(IS_PRESSED(record->event)) {
        //return MACRO(T(KC_KP_ASTERISK), T(KC_KP_SLASH), KC_END);
        tap_code(KC_KP_ASTERISK);
        tap_code(KC_KP_SLASH);
        return false;
      }
    break;
    //ctrl+up then enter
    case DRZ_MACRO_EVE:
      if(IS_PRESSED(record->event)) {
        //return MACRO(D(KC_LEFT_CTRL), T(KC_UP), U(KC_LEFT_CTRL), T(KC_ENTER), KC_END);
        register_code(KC_LEFT_CTRL);
        tap_code(KC_UP);
        unregister_code(KC_LEFT_CTRL);
        tap_code(KC_ENTER);
        return false;
      }
    break;
    //test macro for keymap check
    case DRZ_MACRO_TEST_SENDSTRING:
      if(IS_PRESSED(record->event)) {
        SEND_STRING("1234567890!@#$%^&*()qwertyuiopQWERTYUIOPasdfghjklASDFGHJKL:;zxcvbnmZXCVBNM/\\|.,~+-' \"`_[]<>{}|?");
        return false;
      }
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
  #ifdef DYNAMIC_MACRO_USER_CALL
    uint16_t macro_kc = (keycode == MO(_DYN) ? DM_RSTP : keycode);
    if (!process_record_dynamic_macro(macro_kc, record)) {
      return false;
    }
  #endif
*/
  #ifdef DRZ_MACROS_ENABLED
    if(!process_macros_user(keycode, record)) {
      return false;
    }
  #endif
  #ifdef DRZ_LONGPRESS_ENABLED
    if(!process_longpress(keycode, record)) {
      return false;
    }
  #endif

  bool returnValue = true;
  if(!process_overides(keycode, record)) {
    returnValue = false;
  }
  if(!process_rgb_user(keycode, record)) {
    returnValue = false;
  }
  return returnValue;
}

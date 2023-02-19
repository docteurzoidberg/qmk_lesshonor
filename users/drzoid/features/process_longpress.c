/* Copyright 2023 DrZoid
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "drzoid.h"

uint16_t longpress_time = 0;
uint16_t longpress_timeout = 140;
uint16_t longpress_lastkey = KC_NO;
bool longpress_enabled = true;

bool process_longpress(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed){
    longpress_flush();
    return true;
  }
  switch (keycode) {
    case DRZ_LPUP:
      longpress_increase_timeout(5);
      return false;
    case DRZ_LPDN:
      longpress_decrease_timeout(5);
      return false;
    case DRZ_LPTG:
      longpress_toggle();
      return false;
    case DRZ_LPON:
      longpress_enable();
      return false;
    case DRZ_LPOFF:
      longpress_disable();
      return false;
    case KC_DOT:
      longpress_flush();
      if (!longpress_enabled) return true;
      longpress_on(keycode);
      return false;
  }
  longpress_flush();
  return true;
}

void longpress_increase_timeout(uint16_t amount){
  longpress_timeout+=amount;
}

void longpress_decrease_timeout(uint16_t amount){
  longpress_timeout-=amount;
}

void longpress_on(uint16_t keycode) {
  longpress_time = timer_read();
  longpress_lastkey = keycode;
}

void longpress_flush(void) {

  if (longpress_lastkey == KC_NO) return;

  uint16_t elapsed = timer_elapsed(longpress_time);

  if (elapsed < longpress_timeout) {

      if(
        get_mods() & (
          MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)
        )
      )
      {
  unregister_code(KC_LSFT);
      }


    register_code(longpress_lastkey);
    unregister_code(longpress_lastkey);
    longpress_time = 0;
    longpress_lastkey = KC_NO;
    return;
  }


  switch(longpress_lastkey){
      case KC_COLN:
        register_code(KC_SCLN);
        unregister_code(KC_SCLN);
        break;
      case KC_DOT:
        register_code(KC_COMMA);
        unregister_code(KC_COMMA);
        break;
      default:
        register_code(KC_LSFT);
        register_code(longpress_lastkey);
        unregister_code(longpress_lastkey);
        unregister_code(KC_LSFT);
        break;
  }

  longpress_time = 0;
  longpress_lastkey = KC_NO;
}

void longpress_enable(void) {
  longpress_enabled = true;
}

void longpress_disable(void) {
  longpress_enabled = false;
  longpress_flush();
}

void longpress_toggle(void) {
  if (longpress_enabled) {
    longpress_enabled = false;
    longpress_flush();
  }
  else {
    longpress_enabled = true;
  }
}

bool longpress_state(void) {
  return longpress_enabled;
}

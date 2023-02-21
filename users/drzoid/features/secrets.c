#include QMK_KEYBOARD_H

#include "drzoid.h"

#define MACRO_TIMER 5

#if (__has_include("features/secrets.h") && !defined(NO_SECRETS))
#include "features/secrets.h"
#else
static const char * const secrets[] = {
  "test1",
  "test2",
  "test3",
  "test4",
  "test5"
};
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DRZ_SECRET_1 ... DRZ_SECRET_5: // Secrets!  Externally defined strings, not stored in repo
      if (record->event.pressed) {
        drz_send_secret(keycode - DRZ_SECRET_1);
      }
      return false;
      break;
  }
  return true;
}

bool drz_send_secret(uint8_t index) {
  if(index > 4) return false;
  clear_mods();
  clear_oneshot_mods();
  send_string_with_delay(secrets[index], MACRO_TIMER);
  return true;
}

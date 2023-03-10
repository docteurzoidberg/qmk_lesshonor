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

#pragma once

#undef RGBLIGHT_ANIMATIONS

#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_EFFECT_BREATHING

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_TAPPING
#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT

#define DRZ_QWERTY_INTL_OS
#define LEADER_TIMEOUT 1000
#define MACRO_TIMER 5

//DrZoid> I don't know why, but this is making an error disappear at linking the hex file...
//cf: https://tppt.eu/35j49zemMX2KH7/direct.png
#define SLEEP_LED_TIMER 3

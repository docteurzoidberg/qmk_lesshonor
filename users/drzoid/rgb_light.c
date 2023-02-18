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
#include "rgb_light.h"

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

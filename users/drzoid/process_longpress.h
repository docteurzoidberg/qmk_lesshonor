/* Copyright 2017 Jeremy Cowgar
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

#include "quantum.h"

#ifndef LONGPRESS_TIMEOUT
  #define LONGPRESS_TIMEOUT 175
#endif

bool process_longpress(uint16_t keycode, keyrecord_t *record);

void longpress_increase_timeout(uint16_t amount);
void longpress_decrease_timeout(uint16_t amount);
void longpress_enable(void);
void longpress_disable(void);
void longpress_toggle(void);
bool longpress_state(void);
void longpress_timer_report(void);
void longpress_on(uint16_t keycode);
void longpress_flush(void);

uint16_t longpress_time;
uint16_t longpress_timeout;
uint16_t longpress_lastkey;
bool longpress_enabled;

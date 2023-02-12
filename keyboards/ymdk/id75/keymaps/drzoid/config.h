/* Copyright 2017 Benjamin Kesselring
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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define DRZ_QWERTY_INTL_OS
#define DRZ_USE_UNICODE
#define LONGPRESS_ENABLE

#define LEADER_TIMEOUT 1000

//Unicode chars
#ifdef DRZ_USE_UNICODE
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

#endif


// I don't know why, but this is making an error disappear at linking the hex file
#define SLEEP_LED_TIMER 3

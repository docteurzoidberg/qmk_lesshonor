/*
Drzoid's mirrored 5x15 ortho layout
This layout:
  -> http://www.keyboard-layout-editor.com/#/gists/a59dd1a00a45c5dcd38d9e765675dd41
*/

#include QMK_KEYBOARD_H

#include "drzoid.h"

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
      QK_LOCK,  KC_ESC,   DRZ___1,  DRZ___2,  DRZ___3,  DRZ___4,  DRZ___5,  TO(_MC),  DRZ___6,  DRZ___7,  DRZ___8,  DRZ___9,  DRZ___0,  KC_ESC,   QK_LOCK,
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
      _______,  XXXXXXX,  KC_PSCR,  KC_PAUS,  KC_CALC,  XXXXXXX,  XXXXXXX,  AC_TOGG,  BL_OFF,   BL_ON,    BL_DEC,   RGB_HUI,  BL_INC,   XXXXXXX,  _______,
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

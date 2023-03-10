// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary (26 entries):
//   fitler         -> filter
//   lenght         -> length
//   ouput          -> output
//   widht          -> width
//   heigth         -> height
//   yeild          -> yield
//   ovveride       -> override
//   :zont          -> ils ont
//   :zavaient      -> ils avaient
//   :zavais        -> ils avaient
//   :gnifik        -> magnifique
//   :tarplu        -> plus tard
//   :mouai:        -> je suis sceptique
//   :chepa:        -> je ne sais pas
//   :pomal:        -> pas mal
//   :kapa:         -> qu'a ne pas
//   :jveu:         -> je veux
//   :jfe:          -> je fais
//   :koa:          -> quoi
//   :zill          -> panda
//   :tinpu         -> oulala !
//   :fechier       -> zut alors !
//   :beuh          -> gazon magique
//   :moa           -> moi
//   :petelesburnes -> cela me chagrine profondement
//   :peteburnes    -> agacant

#define AUTOCORRECT_MIN_LENGTH 4 // ":moa"
#define AUTOCORRECT_MAX_LENGTH 14 // ":petelesburnes"
#define DICTIONARY_SIZE 522

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x6C, 0x22, 0x00, 0x04, 0xAD, 0x00, 0x07, 0xB4, 0x00, 0x08, 0xBF, 0x00, 0x0B, 0xCF, 0x00, 0x0E,
    0xF2, 0x00, 0x0F, 0x05, 0x01, 0x15, 0x11, 0x01, 0x16, 0x37, 0x01, 0x17, 0x92, 0x01, 0x18, 0xE3,
    0x01, 0x00, 0x44, 0x32, 0x00, 0x08, 0x6D, 0x00, 0x0C, 0x79, 0x00, 0x0F, 0x92, 0x00, 0x18, 0xA0,
    0x00, 0x00, 0x52, 0x39, 0x00, 0x13, 0x42, 0x00, 0x00, 0x0E, 0x2C, 0x00, 0x83, 0x71, 0x75, 0x6F,
    0x69, 0x00, 0x44, 0x49, 0x00, 0x08, 0x59, 0x00, 0x00, 0x0E, 0x2C, 0x00, 0x84, 0x71, 0x75, 0x27,
    0x61, 0x20, 0x6E, 0x65, 0x20, 0x70, 0x61, 0x73, 0x00, 0x0B, 0x06, 0x2C, 0x00, 0x85, 0x6A, 0x65,
    0x20, 0x6E, 0x65, 0x20, 0x73, 0x61, 0x69, 0x73, 0x20, 0x70, 0x61, 0x73, 0x00, 0x09, 0x0D, 0x2C,
    0x00, 0x82, 0x65, 0x20, 0x66, 0x61, 0x69, 0x73, 0x00, 0x04, 0x18, 0x12, 0x10, 0x2C, 0x00, 0x85,
    0x6A, 0x65, 0x20, 0x73, 0x75, 0x69, 0x73, 0x20, 0x73, 0x63, 0x65, 0x70, 0x74, 0x69, 0x71, 0x75,
    0x65, 0x00, 0x04, 0x10, 0x12, 0x13, 0x2C, 0x00, 0x84, 0x61, 0x73, 0x20, 0x6D, 0x61, 0x6C, 0x00,
    0x08, 0x19, 0x0D, 0x2C, 0x00, 0x83, 0x65, 0x20, 0x76, 0x65, 0x75, 0x78, 0x00, 0x12, 0x10, 0x2C,
    0x00, 0x80, 0x69, 0x00, 0x0F, 0x0C, 0x08, 0x1C, 0x00, 0x83, 0x69, 0x65, 0x6C, 0x64, 0x00, 0x07,
    0x0C, 0x15, 0x08, 0x19, 0x19, 0x12, 0x00, 0x85, 0x65, 0x72, 0x72, 0x69, 0x64, 0x65, 0x00, 0x57,
    0xD6, 0x00, 0x18, 0xDF, 0x00, 0x00, 0x0A, 0x0C, 0x08, 0x0B, 0x00, 0x81, 0x68, 0x74, 0x00, 0x08,
    0x05, 0x2C, 0x00, 0x83, 0x67, 0x61, 0x7A, 0x6F, 0x6E, 0x20, 0x6D, 0x61, 0x67, 0x69, 0x71, 0x75,
    0x65, 0x00, 0x0C, 0x09, 0x0C, 0x11, 0x0A, 0x2C, 0x00, 0x85, 0x6D, 0x61, 0x67, 0x6E, 0x69, 0x66,
    0x69, 0x71, 0x75, 0x65, 0x00, 0x0F, 0x0C, 0x1D, 0x2C, 0x00, 0x83, 0x70, 0x61, 0x6E, 0x64, 0x61,
    0x00, 0x08, 0x00, 0x4C, 0x1A, 0x01, 0x0F, 0x2D, 0x01, 0x00, 0x0B, 0x06, 0x08, 0x09, 0x2C, 0x00,
    0x86, 0x7A, 0x75, 0x74, 0x20, 0x61, 0x6C, 0x6F, 0x72, 0x73, 0x20, 0x21, 0x00, 0x17, 0x0C, 0x09,
    0x00, 0x83, 0x6C, 0x74, 0x65, 0x72, 0x00, 0x48, 0x3E, 0x01, 0x0C, 0x7F, 0x01, 0x00, 0x11, 0x15,
    0x18, 0x05, 0x00, 0x48, 0x4A, 0x01, 0x16, 0x58, 0x01, 0x00, 0x17, 0x08, 0x13, 0x2C, 0x00, 0x89,
    0x61, 0x67, 0x61, 0x63, 0x61, 0x6E, 0x74, 0x00, 0x08, 0x0F, 0x08, 0x17, 0x08, 0x13, 0x2C, 0x00,
    0x8C, 0x63, 0x65, 0x6C, 0x61, 0x20, 0x6D, 0x65, 0x20, 0x63, 0x68, 0x61, 0x67, 0x72, 0x69, 0x6E,
    0x65, 0x20, 0x70, 0x72, 0x6F, 0x66, 0x6F, 0x6E, 0x64, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x00, 0x04,
    0x19, 0x04, 0x1D, 0x2C, 0x00, 0x85, 0x69, 0x6C, 0x73, 0x20, 0x61, 0x76, 0x61, 0x69, 0x65, 0x6E,
    0x74, 0x00, 0x4B, 0x9C, 0x01, 0x11, 0xB2, 0x01, 0x18, 0xD9, 0x01, 0x00, 0x47, 0xA3, 0x01, 0x0A,
    0xAA, 0x01, 0x00, 0x0C, 0x1A, 0x00, 0x81, 0x74, 0x68, 0x00, 0x11, 0x08, 0x0F, 0x00, 0x81, 0x74,
    0x68, 0x00, 0x48, 0xB9, 0x01, 0x12, 0xCD, 0x01, 0x00, 0x0C, 0x04, 0x19, 0x04, 0x1D, 0x2C, 0x00,
    0x87, 0x69, 0x6C, 0x73, 0x20, 0x61, 0x76, 0x61, 0x69, 0x65, 0x6E, 0x74, 0x00, 0x1D, 0x2C, 0x00,
    0x83, 0x69, 0x6C, 0x73, 0x20, 0x6F, 0x6E, 0x74, 0x00, 0x13, 0x18, 0x12, 0x00, 0x82, 0x74, 0x70,
    0x75, 0x74, 0x00, 0x4F, 0xEA, 0x01, 0x13, 0xFB, 0x01, 0x00, 0x13, 0x15, 0x04, 0x17, 0x2C, 0x00,
    0x85, 0x70, 0x6C, 0x75, 0x73, 0x20, 0x74, 0x61, 0x72, 0x64, 0x00, 0x11, 0x0C, 0x17, 0x2C, 0x00,
    0x84, 0x6F, 0x75, 0x6C, 0x61, 0x6C, 0x61, 0x20, 0x21, 0x00
};

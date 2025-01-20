// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file keymap.c
 * @brief Pascal's keymap for the ZSA Voyager.
 *
 * This file defines what keycode is performed by each key position. See also
 * getreuer.c for definitions of macros, etc. used in my keymap.
 */

#include QMK_KEYBOARD_H

#include "voyager.h"
#include "layout.h"
#include "getreuer.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [BASE] = LAYOUT_LR(  // Base layer: Magic Sturdy. */
  /*   KC_GRV , G(KC_TAB), SELLINE, KC_DOWN, KC_UP  , KC_BTN1, */
  /*   KC_TAB , KC_V   , KC_M   , KC_L   , KC_C   , KC_P   , */
  /*   KC_BSPC, HOME_X , HOME_C , HOME_B , HOME_V , KC_Y   , */
  /*   WIN_COL, HOME_C , KC_K   , KC_J   , NUM_G  , KC_W   , */
  /*                                                KC_UNDS, KC_SPC , */
  /**/
  /*                     KC_HOME, KC_LEFT, KC_RGHT , KC_END , KC_DEL , KC_MPLY, */
  /*                     KC_B   , MAGIC  , KC_U   , KC_O   , KC_Q   , KC_SLSH, */
  /*                     KC_F   , HOME_M , CKC_COMM , HOME_DOT , CKC_L , KC_QUOT, */
  /*                     KC_Z   , KC_H   , KC_COMM, KC_DOT , CKC_S, KC_ENT , */
  /*            QK_REP , KC_ESC */
  /* ), */

  [BASE] = LAYOUT_LR(  // Base layer: Magic Sturdy.
    KC_GRV  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
    KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
    CKC_CAPS, CKC_A  , CKC_S  , KC_D   , KC_F   , NUM_G  ,
    KC_LSFT , KC_Z   , HOME_X , HOME_C , KC_V   , KC_B   ,
                                                  CKC_ENT, KC_LCTL,

                      KC_6   , KC_7   , KC_8    , KC_9   , KC_0     , KC_MINS,
                      KC_Y   , KC_U   , KC_I    , KC_O   , KC_P     , KC_BSLS,
                      KC_H   , KC_J   , KC_K    , CKC_L  , CKC_SCLN , KC_QUOT,
                      KC_N   , KC_M   , KC_COMM , HOME_DOT, KC_SLSH, MAGIC  ,
             CKC_BSPC,KC_SPC
  ),

  [SYM] = LAYOUT_LR(  // Symbol layer.
    _______, C(KC_Z), C(KC_V), C(KC_A), C(KC_C), C(KC_X),
    TMUXESC, MO(FUN), _______, _______, _______, _______,
    _______, KC_LSFT, _______, _______, _______, _______,
    _______, _______, RCTL(KC_RSFT), KC_LALT, KC_LCTL, USRNAME,
                                              _______, _______,

                      KC_EQL , KC_AMPR, KC_ASTR, KC_SLSH, _______, KC_MUTE,
                      KC_HASH, KC_LBRC, KC_RBRC, KC_PIPE, SRCHSEL, _______,
                      KC_DLR , KC_LPRN, KC_RPRN, KC_PERC, KC_UNDS, KC_DQUO,
                      KC_TILD, KC_LCBR, KC_RCBR, _______, KC_QUES, _______,
             _______, KC_AT
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LSFT, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, _______, RCTL(KC_RSFT), KC_LALT,  KC_LCTL, XXXXXXX,
                                                 TO(BASE), QK_LLCK,

                      KC_EQL , KC_7   , KC_8   , KC_9   , _______, _______,
                      _______, KC_4   , KC_5   , KC_6   , _______, _______,
                      KC_PLUS, KC_1   , KC_2   , KC_3   , KC_ASTR, _______,
                      KC_MINS, KC_0   , _______, KC_DOT , KC_SLSH, TO(BASE),
             KC_0   , KC_0 
  ),

  [WIN] = LAYOUT_LR(  // Window management layer.
    RM_TOGG, RGB_DEF, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU,
    XXXXXXX, XXXXXXX, XXXXXXX, C(S(KC_UP)), XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, C(S(KC_LEFT)), C(S(KC_DOWN)), C(S(KC_RIGHT)),XXXXXXX,
    XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, G(KC_SPC),

                      XXXXXXX, C(S(KC_7)), C(S(KC_8)), C(S(KC_9)), XXXXXXX, XXXXXXX,
                      G(KC_TAB), C(S(KC_4)), C(S(KC_5)), C(S(KC_6)), XXXXXXX, XXXXXXX,
                      XXXXXXX, C(S(KC_1)), C(S(KC_2)), C(S(KC_3)), C(S(KC_RGHT)), XXXXXXX,
                      XXXXXXX, C(S(KC_7)), C(S(KC_6)), C(S(KC_5)), KC_VOLD , KC_VOLU,
             QK_REP , XXXXXXX
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 TO(BASE), QK_LLCK,

                      _______, _______, _______, _______, _______, QK_BOOT,
                      XXXXXXX, KC_F8  , KC_F9  , KC_F4  , KC_F10 , XXXXXXX,
                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F11 , XXXXXXX,
                      XXXXXXX, KC_F7  , KC_F6  , KC_F5  , KC_F12 , _______,
             XXXXXXX, _______
  ),

};


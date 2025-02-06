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
  /*   KC_BSPC, MOD_ALT2 , MOD_CTRL1 , HOME_B , LAY_ARR , KC_Y   , */
  /*   LAY_WIN2, MOD_CTRL1 , KC_K   , KC_J   , LAY_NUM  , KC_W   , */
  /*                                                KC_UNDS, KC_SPC , */
  /**/
  /*                     KC_HOME, KC_LEFT, KC_RGHT , KC_END , KC_DEL , KC_MPLY, */
  /*                     KC_B   , MAGIC  , KC_U   , KC_O   , KC_Q   , KC_SLSH, */
  /*                     KC_F   , MOD_ALT1 , MOD_GUI3 , LAY_WIN1, CKC_SCLN , KC_QUOT, */
  /*                     KC_Z   , KC_H   , KC_COMM, KC_DOT , CKC_S, KC_ENT , */
  /*            QK_REP , KC_ESC */
  /* ), */

  /* [BASE] = LAYOUT_LR(  // Base layer: Graphite */
  /*   KC_GRV  , KC_1   , KC_2     , KC_3     , KC_4     , KC_5   , */
  /*   KC_TAB  , KC_B   , KC_L     , LAY_WIN1, KC_W     , KC_Z   , */
  /*   CKC_CAPS, KC_N   , KC_R     , MOD_SFT1 , LAY_NUM  , KC_G   , */
  /*   KC_LSFT , KC_Q   , KC_X     , KC_M     , KC_C     , KC_V   , */
  /*                              LEFT_THUMB_SMALL   , LEFT_THUMB_BIG, */
  /**/
  /*                     KC_6   , KC_7     , KC_8      , KC_9     , KC_0     , KC_MINS, */
  /*                     KC_QUOT, LAY_ARR, LAY_WIN2  , KC_U     , KC_J     , KC_SCLN, */
  /*                     KC_Y   , KC_H     , KC_A      , KC_E     , CKC_SCLN , KC_COMM, */
  /*                     KC_K   , KC_P     , KC_DOT    , KC_MINS  , KC_SLSH  , MOD_GUI3, */
  /*            RIGHT_THUMB_BIG , RIGHT_THUMB_SMALL */
  /* ), */

  [BASE] = LAYOUT_LR(  // Base layer
    KC_GRV  , KC_1    , KC_2     , KC_3     , KC_4     , KC_5   ,
    KC_TAB  , KC_Q    , KC_W     , LAY_WIN1 , KC_R     , KC_T   ,
    CKC_CAPS, KC_A    , KC_S     , LAY_QUICK, LAY_NUM  , KC_G   ,
    KC_LSFT , KC_Z    , KC_X     , KC_C     , KC_V     , KC_B   ,
                                   LEFT_THUMB_SMALL    , LEFT_THUMB_BIG,

                      KC_6   , KC_7     , KC_8      , KC_9     , KC_0     , KC_MINS,
                      KC_Y   , LAY_ARR  , LAY_WIN2  , KC_O     , KC_P     , KC_BSLS,
                      KC_H   , KC_J     , KC_K      , KC_L     , KC_SCLN  , KC_QUOT,
                      KC_N   , KC_M     , KC_COMM   , KC_DOT   , KC_SLSH  , MOD_GUI3,
             RIGHT_THUMB_BIG , RIGHT_THUMB_SMALL
  ),

  [SYM1] = LAYOUT_LR(  // Symbol layer.
    TMUXESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
    XXXXXXX, XXXXXXX, KC_AT  , KC_HASH, KC_ASTR, XXXXXXX,
    QK_LLCK, KC_EXLM, KC_UNDS, KC_DQUO, KC_MINS, KC_PLUS,
    XXXXXXX, XXXXXXX, KC_TILD, KC_PIPE, KC_AMPR, XXXXXXX,
                                                 _______, _______,

                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
                      XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL , XXXXXXX, XXXXXXX,
                      KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR , KC_BSLS, XXXXXXX,
                      XXXXXXX, KC_LCBR, KC_RCBR, KC_PERC, KC_QUES, XXXXXXX,
             _______, _______
  ),

  [QUICKMENU] = LAYOUT_LR(  // Symbol layer.
    TMUXESC, C(KC_Z), C(KC_V), C(KC_A), C(KC_C), C(KC_X),
    _______, MO(FUN), _______, _______, _______, _______,
    QK_LLCK, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, USRNAME,
                                                 _______, _______,

                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_AT  , KC_HASH, KC_ASTR , XXXXXXX, XXXXXXX,
                      KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_TILD, KC_PIPE, KC_AMPR , XXXXXXX, XXXXXXX,
             _______, _______
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    QK_LLCK, KC_LPRN, KC_RPRN, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,
                                                 _______, _______,

                      KC_EQL , KC_SLSH, KC_ASTR, KC_MINS, XXXXXXX, KC_MINS,
                      KC_EQL , KC_7   , KC_8   , KC_9   , KC_LPRN, KC_RPRN,
                      KC_DOT , KC_4   , KC_5   , KC_6   , KC_PLUS, KC_PERC,
                      XXXXXXX, KC_1   , KC_2   , KC_3   , KC_SLSH, XXXXXXX,
             _______, KC_0   
  ),

  [WIN] = LAYOUT_LR(  // Window management layer.
    RM_TOGG  , RGB_DEF   , RM_NEXT      , RM_HUEU      , RM_SATU       , RM_VALU,
    G(KC_TAB), C(A(KC_Q)), XXXXXXX      , C(A(KC_UP))  , XXXXXXX       , C(A(KC_T)),
    XXXXXXX  , XXXXXXX   , C(A(KC_LEFT)), C(A(KC_DOWN)), C(A(KC_RIGHT)), G(S(KC_S)),
    XXXXXXX  , XXXXXXX   , LALT(KC_F4)  , XXXXXXX      , XXXXXXX       , XXXXXXX,
                                                         _______, _______,

                      XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX, XXXXXXX,
                      C(A(KC_Y)), C(A(KC_7)), C(A(KC_8)), C(A(KC_9)), XXXXXXX, XXXXXXX,
                      C(A(KC_H)), C(A(KC_4)), C(A(KC_5)), C(A(KC_6)), KC_VOLD, KC_VOLU,
                      C(A(KC_N)), C(A(KC_1)), C(A(KC_2)), C(A(KC_3)), XXXXXXX, XXXXXXX,
             KC_DEL , G(KC_SPC)
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_LLCK, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      KC_SCRL, KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F7  , KC_F8  , KC_F9  , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F4  , KC_F5  , KC_F6  , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX,
             _______, _______
  ),

  [NAV] = LAYOUT_LR(  // Mouse layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, MS_UP  , XXXXXXX, XXXXXXX,
    QK_LLCK, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, XXXXXXX, XXXXXXX,
                      XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(BASE),
             _______, _______
  ),

  [ARR] = LAYOUT_LR(  // Arrow layer.
    _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP, _______,
    _______, XXXXXXX, KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX,
    QK_LLCK, KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      XXXXXXX, XXXXXXX     , XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_VOLU, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_VOLD, XXXXXXX     , XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_MUTE, XXXXXXX     , XXXXXXX  , XXXXXXX, XXXXXXX, TO(BASE),
             _______, _______
  ),


};


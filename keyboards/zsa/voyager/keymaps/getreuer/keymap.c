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
  [GRAPHITE] = LAYOUT_LR(  // layer: Graphite
    KC_GRV         , KC_1     , KC_2     , KC_3      , KC_4      , KC_5   ,
    LAY_NAV        , KC_B     , KC_L     , KC_D      , KC_W      , KC_Z   ,
    CKC_CAPS       , gMOD_SFT1, KC_R     , gLAY_NUM  , gLAY_QUICK, KC_G   ,
    LSFT_T(KC_CAPS), KC_Q     , KC_X     , KC_M      , KC_C      , KC_V   ,
                           LEFT_THUMB_SMALL   , LEFT_THUMB_BIG,
  
                      KC_6   , KC_7      , KC_8      , KC_9     , KC_0     , XXXXXXX,
                      KC_QUOT, KC_F      , KC_O      , KC_U     , KC_J     , KC_SCLN,
                      KC_Y   , KC_H      , KC_A      , KC_E     , gMOD_SFT2, KC_COMM,
                      KC_K   , KC_P      , KC_DOT    , KC_MINS  , KC_SLSH  , TO(BASE),  
             RIGHT_THUMB_BIG , RIGHT_THUMB_SMALL 
  ),

  [LAY_CTRL] = LAYOUT_LR(  // CTRL layer
    C(KC_GRV)  , C(KC_1) , C(KC_2) , C(KC_3) , C(KC_4) , C(KC_5) ,
    A(KC_ENT)  , C(KC_B) , C(KC_L) , C(KC_D) , C(KC_W) , C(KC_Z) ,
    C(KC_A)    , C(KC_N) , C(KC_R) , C(KC_T) , C(KC_S) , C(KC_G) ,
    G(S(KC_S)) , C(KC_Q) , C(KC_X) , C(KC_M) , C(KC_C) , C(KC_V),
                                          _______    , _______,

                      C(KC_6)   , C(KC_7)     , C(KC_8)      , C(KC_9)    , C(KC_0)    , XXXXXXX,
                      C(KC_QUOT), C(KC_F)     , C(KC_O)      , C(KC_O)    , C(KC_U)    , C(KC_SCLN),
                      C(KC_Y)   , C(KC_H)     , C(KC_A)      , C(KC_E)    , C(KC_I)    , C(KC_COMM),
                      C(KC_K)   , C(KC_P)     , C(KC_DOT)    , C(KC_MINS) , C(KC_SLSH) , C(KC_ENT),  
             C(KC_BSPC), C(KC_F)
  ),

  // TMUXESC
  [SYM1] = LAYOUT_LR(  // Symbol layer (right small key)
    KC_GRV , KC_F1  , KC_F2  , KC_F3     , KC_F4     , KC_F5  ,
    KC_F12 , XXXXXXX, KC_AT  , KC_LBRC   , KC_RBRC   , XXXXXXX,
    KC_QUES, KC_COLN, KC_CIRC, KC_LPRN   , KC_RPRN   , KC_DLR , 
    XXXXXXX, XXXXXXX, KC_TILD, KC_LCBR   , KC_RCBR   , XXXXXXX,
                                          _______    , _______,

                      KC_F6     , KC_F7     , KC_F8  , KC_F9     , KC_F10    , KC_F11 ,
                      KC_UNDS   , KC_AMPR   , KC_PIPE, KC_BSLS   , KC_PERC   , XXXXXXX,
                      KC_KP_PLUS, KC_HASH   , KC_EQL , KC_EXLM   , KC_COLN   , KC_QUES,
                      KC_ASTR   , KC_AT     , KC_RABK, KC_DQUO   , KC_LABK   , QK_LLCK,
             _______, _______
  ),

  [SYM2] = LAYOUT_LR(  // Symbol layer.2
    KC_F12 , KC_F1  , KC_F2  , KC_F3     , KC_F4     , KC_F5  ,
    KC_COLN, KC_PERC, KC_GRV , KC_LBRC   , KC_RBRC   , KC_TILD,
    KC_QUES, KC_SCLN, KC_CIRC, KC_LPRN   , KC_RPRN   , KC_DLR , 
    XXXXXXX, XXXXXXX, KC_DQUO, KC_LCBR   , KC_RCBR   , XXXXXXX,
                                          _______    , _______,

                      KC_F6     , KC_F7     , KC_F8  , KC_F9  , KC_F10    , KC_F11 ,
                      KC_TILD   , KC_LBRC   , KC_RBRC, KC_GRV , KC_PERC   , KC_COLN,
                      KC_CIRC   , KC_LPRN   , KC_RPRN, KC_DLR , KC_SCLN   , KC_QUES,
                      XXXXXXX   , KC_LCBR   , KC_RCBR, KC_DQUO, XXXXXXX   , QK_LLCK,
             _______, _______
  ),
 
  [NUM] = LAYOUT_LR(  // Number layer.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,
    _______, _______, XXXXXXX, KC_EQL , KC_DOT , XXXXXXX,  
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,
                                                 _______, _______,

                      XXXXXXX   , KC_SLSH, KC_ASTR, KC_LPRN, KC_RPRN   , XXXXXXX,
                      KC_EQL    , KC_7   , KC_8   , KC_9   , KC_PERC   , XXXXXXX,
                      KC_KP_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS   , KC_COMM,
                      KC_ASTR   , KC_1   , KC_2   , KC_3   , KC_SLSH   , QK_LLCK,
             _______, KC_0   
  ),

  [BASE] = LAYOUT_LR(  // Base layer: QWERTY
    KC_GRV  , KC_1    , KC_2     , KC_3     , KC_4     , KC_5   ,
    LAY_NAV , KC_Q    , KC_W     , KC_E     , KC_R     , KC_T   ,
    KC_LCTL , KC_A    , KC_S     , KC_D     , KC_F     , KC_G   ,
    KC_LSFT , KC_Z    , KC_X     , KC_C     , KC_V     , KC_B   ,
                                   LEFT_THUMB_SMALL    , LEFT_THUMB_BIG,

                      // KC_Y    , KC_U     , KC_I      , LAY_WIN2 , KC_P     , KC_BSLS,
                      // KC_H    , KC_J     , KC_K      , KC_L     , MOD_SFT2 , KC_QUOT,
                      // KC_N    , MOD_CTL2 , MOD_ALT2  , KC_DOT   , MOD_GUI2 , TO(GRAPHITE),
                      KC_6    , KC_7     , KC_8      , KC_9     , KC_0     , KC_MINS,
                      KC_Y    , KC_U     , KC_I      , KC_O     , KC_P     , KC_BSLS,
                      KC_H    , KC_J     , KC_K      , KC_L     , MOD_SFT2 , KC_QUOT,
                      KC_N    , KC_M     , KC_COMM   , KC_DOT   , KC_SLSH  , TO(GRAPHITE),
             RIGHT_THUMB_BIG  , RIGHT_THUMB_SMALL
  ),

  [QUICKMENU] = LAYOUT_LR(  // Symbol layer.
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
    KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10 , KC_F11 ,
                      KC_HOME, KC_PGUP, KC_PGDN, KC_END  , XXXXXXX, XXXXXXX,
                      KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_INS , XXXXXXX,
                      KC_SCRL, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, XXXXXXX, XXXXXXX, QK_LLCK,
             KC_DEL, _______
  ),

  [NAV] = LAYOUT_LR(  // Mouse layer.
    _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP, _______,
    _______, XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX,
    _______, KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 MS_BTN1, MS_BTN2,

                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, XXXXXXX, XXXXXXX,
                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, XXXXXXX,
                      KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX, QK_LLCK,
             MS_BTN2, MS_BTN1
  ),


  [WIN] = LAYOUT_LR(  // Window management layer.
    /* RM_TOGG  , RGB_DEF   , RM_NEXT      , RM_HUEU      , RM_SATU       , RM_VALU, */
    KC_F12 , KC_F1  , KC_F2  , KC_F3     , KC_F4     , KC_F5  ,
    G(KC_TAB), C(A(KC_Q)), XXXXXXX      , C(A(KC_UP))  , XXXXXXX       , C(A(KC_T)),
    XXXXXXX  , XXXXXXX   , C(A(KC_LEFT)), C(A(KC_DOWN)), C(A(KC_RIGHT)), G(S(KC_S)),
    XXXXXXX  , XXXXXXX   , LALT(KC_F4)  , XXXXXXX      , XXXXXXX       , XXXXXXX,
                                                         _______     , _______,

                      KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10 , KC_F11 ,
                      C(A(KC_Y)), C(A(KC_7)), C(A(KC_8)), C(A(KC_9)), KC_VOLD, KC_VOLU,
                      C(A(KC_H)), C(A(KC_4)), C(A(KC_5)), C(A(KC_6)), XXXXXXX, XXXXXXX,
                      C(A(KC_N)), C(A(KC_1)), C(A(KC_2)), C(A(KC_3)), XXXXXXX, QK_LLCK,
             KC_DEL , G(KC_SPC)
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, XXXXXXX,
    _______, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 _______, _______,

                      KC_SCRL, KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F7  , KC_F8  , KC_F9  , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F4  , KC_F5  , KC_F6  , XXXXXXX, XXXXXXX,
                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , XXXXXXX, QK_LLCK,
             _______, _______
  ),


};


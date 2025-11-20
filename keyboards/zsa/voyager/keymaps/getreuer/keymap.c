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
    CKC_CAPS       , gMOD_SFT1, gLAY_NUM , T_MOD     , S_MOD     , G_MOD  ,
    KC_LSFT        , KC_Q     , KC_X     , KC_M      , KC_C      , KC_V   ,
                           LEFT_THUMB_SMALL   , LEFT_THUMB_BIG,
  
                      KC_6   , KC_7      , KC_8      , KC_9     , KC_0     , KC_BSLS,
                      KC_QUOT, KC_F      , KC_O      , KC_U     , KC_J     , KC_SCLN,
                      KC_Y   , KC_H      , KC_A      , KC_E     , gMOD_SFT2, KC_COMM,
                      KC_K   , KC_P      , KC_DOT    , KC_MINS  , KC_SLSH  , TO(BASE),  
             RIGHT_THUMB_BIG , RIGHT_THUMB_SMALL 
  ),

  [G_BASIC] = LAYOUT_LR(
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                              KC_LALT , XXXXXXX , //  LT(G_ADV, KC_LALT),

                      S(C(KC_6))   , S(C(KC_7))   , S(C(KC_8))  , S(C(KC_9))    , S(C(KC_0))   , S(A(KC_Q)),
                      S(C(KC_F13)) , S(C(KC_F))   , S(C(KC_O))  , S(C(KC_U))    , S(C(KC_J))   , S(C(KC_W)),
                      S(C(KC_LEFT)), S(C(KC_DOWN)), S(C(KC_UP)) , S(C(KC_RIGHT)), S(C(KC_I))   , S(C(KC_N)),
                      S(C(KC_K))   , S(C(KC_P))   , S(C(KC_DOT)), S(C(KC_MINS)) , S(C(KC_SLSH)), S(C(KC_F16)),
             XXXXXXX , S(C(KC_F14))
  ),

  [T_BASIC] = LAYOUT_LR(
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                              KC_LALT , S(C(KC_F15)), // LT(T_ADV, KC_LALT),

                      XXXXXXX     , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX     , XXXXXXX,
                      XXXXXXX     , S(C(KC_F7)), S(C(KC_F8)), S(C(KC_F9)), XXXXXXX     , XXXXXXX,
                      S(C(KC_F20)), S(C(KC_F4)), S(C(KC_F5)), S(C(KC_F6)), S(C(KC_F23)), XXXXXXX,
                      S(C(KC_F21)), S(C(KC_F1)), S(C(KC_F2)), S(C(KC_F3)), XXXXXXX     , XXXXXXX,
             S(C(KC_F17)), S(C(KC_F18))
  ),

//   [LAY_CTRL] = LAYOUT_LR(  // CTRL layer
//     C(KC_GRV)  , C(KC_1) , C(KC_2) , C(KC_3) , C(KC_4) , C(KC_5) ,
//     A(KC_ENT)  , C(KC_B) , C(KC_L) , C(KC_D) , C(KC_W) , C(KC_Z) ,
//     C(KC_A)    , C(KC_N) , C(KC_R) , C(KC_T) , C(KC_S) , C(KC_G) ,
//     G(S(KC_S)) , C(KC_Q) , C(KC_X) , C(KC_M) , C(KC_C) , C(KC_V),
//                                           _______    , _______,
// 
//                       C(KC_6)   , C(KC_7)     , C(KC_8)      , C(KC_9)    , C(KC_0)    , C(KC_SPACE),
//                       C(KC_QUOT), C(KC_F)     , C(KC_O)      , C(KC_O)    , C(KC_U)    , C(KC_SCLN),
//                       C(KC_Y)   , C(KC_H)     , C(KC_A)      , C(KC_E)    , C(KC_I)    , C(KC_COMM),
//                       C(KC_K)   , C(KC_P)     , C(KC_DOT)    , C(KC_MINS) , C(KC_SLSH) , C(KC_ENT),  
//              C(KC_BSPC), C(KC_F)
//   ),

  [LAY_ALT] = LAYOUT_LR(  // ALT layer
    A(KC_GRV)  , A(KC_1) , A(KC_2) , A(KC_3)   , A(KC_4)   , A(KC_5) ,
    XXXXXXX    , A(KC_B) , A(KC_L) , A(KC_D)   , A(KC_W)   , A(KC_Z) ,
    A(KC_A)    , A(KC_N) , A(KC_R) , LT(T_ADV, XXXXXXX), A(KC_S)   , LT(G_ADV, XXXXXXX) ,
    XXXXXXX    , A(KC_Q) , A(KC_X) , A(KC_M)   , A(KC_C)   , A(KC_V),
                                          KC_LCTL, _______,

                      A(KC_6)   , A(KC_7)     , A(KC_8)      , A(KC_9)    , A(KC_0)    , A(KC_SPACE),
                      A(KC_QUOT), A(KC_F)     , A(KC_O)      , A(KC_O)    , A(KC_U)    , A(KC_SCLN),
                      A(KC_Y)   , A(KC_H)     , A(KC_A)      , A(KC_E)    , A(KC_I)    , A(KC_COMM),
                      A(KC_K)   , A(KC_P)     , A(KC_DOT)    , A(KC_MINS) , A(KC_SLSH) , A(KC_ENT),  
             A(KC_BSPC), A(KC_SPACE)
  ),

  [LAY_CTRL] = LAYOUT_LR(  // Left Sym layer
    KC_TILD    , KC_F1    , KC_F2    , KC_F3     , KC_F4     , KC_F5   ,
    A(KC_TAB)  , XXXXXXX  , KC_PERC  , KC_LBRC   , KC_BSLS   , KC_PIPE ,
    C(KC_A)    , KC_UNDS  , KC_CIRC  , KC_LPRN   , KC_EQL    , KC_DLR  ,
    G(S(KC_S)) , XXXXXXX  , C(KC_X)  , KC_LCBR   , C(KC_C)   , C(KC_V) ,
                                                  _______    , _______ ,

                      KC_F6      , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11 ,
                      KC_DQUO    , KC_HASH   , KC_RBRC   , KC_EXLM   , KC_PERC   , KC_F12 ,
                      KC_KP_PLUS , KC_ASTR   , KC_RPRN   , KC_QUES   , KC_COLN   , A(KC_SPACE),
                      KC_ASTR    , KC_AT     , KC_RCBR   , KC_LABK   , KC_RABK   , C(KC_ENT),
             C(KC_BSPC), C(KC_F)
),

  [SYM1] = LAYOUT_LR(  // right sym layer
    KC_TILD    , KC_F1    , KC_F2    , KC_F3     , KC_F4     , KC_F5   ,
    XXXXXXX    , XXXXXXX  , KC_PERC  , KC_LBRC   , KC_BSLS   , KC_PIPE ,
    XXXXXXX    , KC_UNDS  , KC_CIRC  , KC_LPRN   , KC_EQL    , KC_DLR  ,
    XXXXXXX    , XXXXXXX  , C(KC_X)  , KC_LCBR   , C(KC_C)   , C(KC_V) ,
                                          _______    , _______,
 
                      KC_F6      , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11 ,
                      KC_DQUO    , KC_HASH   , KC_RBRC   , KC_EXLM   , KC_PERC   , KC_F12 ,
                      KC_KP_PLUS , KC_ASTR   , KC_RPRN   , KC_QUES   , KC_COLN   , A(KC_SPACE),
                      KC_ASTR    , KC_AT     , KC_RCBR   , KC_LABK   , KC_RABK   , C(KC_ENT),
             _______, C(KC_F)
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,
    _______, _______, XXXXXXX, KC_DOT , KC_EQL , XXXXXXX,  
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,
                                                 _______, _______,

                      XXXXXXX   , KC_SLSH, KC_LPRN, KC_RPRN, XXXXXXX   , XXXXXXX,
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

                      KC_6    , KC_7     , KC_8      , KC_9     , KC_0     , KC_MINS,
                      KC_Y    , KC_U     , KC_I      , KC_O     , KC_P     , KC_BSLS,
                      KC_H    , KC_J     , KC_K      , KC_L     , MOD_SFT2 , KC_QUOT,
                      KC_N    , KC_M     , KC_COMM   , KC_DOT   , KC_SLSH  , TO(GRAPHITE),
             RIGHT_THUMB_BIG  , RIGHT_THUMB_SMALL
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


  [S_LAYER] = LAYOUT_LR(
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

    /* RM_TOGG  , RGB_DEF   , RM_NEXT      , RM_HUEU      , RM_SATU       , RM_VALU, */

  [G_ADV] = LAYOUT_LR(  
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                              KC_LCTL, XXXXXXX ,

                      XXXXXXX         , XXXXXXX   , XXXXXXX     , XXXXXXX      , XXXXXXX      , XXXXXXX,
                      XXXXXXX         , XXXXXXX   , XXXXXXX     , XXXXXXX      , XXXXXXX      , XXXXXXX,
                      C(S(A(KC_LEFT))), C(S(A(KC_DOWN))), C(S(A(KC_UP))) , C(S(A(KC_RIGHT))), C(S(A(KC_I)))   , XXXXXXX,
                      XXXXXXX         , XXXXXXX   , XXXXXXX     , XXXXXXX      , XXXXXXX      , XXXXXXX,
             XXXXXXX , XXXXXXX
  ),

  [T_ADV] = LAYOUT_LR(  // Symbol layer.
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
    KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               KC_LCTL, XXXXXXX ,

                      XXXXXXX , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX, XXXXXXX,
                      XXXXXXX , C(S(A(KC_F7))), C(S(A(KC_8))), C(S(A(KC_9))), XXXXXXX, XXXXXXX,
                      XXXXXXX , C(S(A(KC_F4))), C(S(A(KC_5))), C(S(A(KC_6))), XXXXXXX, XXXXXXX,
                      XXXXXXX , C(S(A(KC_F1))), C(S(A(KC_2))), C(S(A(KC_3))), XXXXXXX, XXXXXXX,
             _______, _______
  ),



};


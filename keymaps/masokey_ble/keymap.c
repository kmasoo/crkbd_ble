/*
Copyright 2018 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include "action_layer.h"
#include "send_string_keycodes.h"

extern keymap_config_t keymap_config;


enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    NUMPAD,
    BACKLIT,
    RGBRST,
};


enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
};


enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______    KC_TRNS
#define KC_XXXXX    KC_NO


#define KC_RST      RESET
#define KC_LRST     RGBRST
#define KC_LTOG     RGB_TOG
#define KC_LHUI     RGB_HUI
#define KC_LHUD     RGB_HUD
#define KC_LSAI     RGB_SAI
#define KC_LSAD     RGB_SAD
#define KC_LVAI     RGB_VAI
#define KC_LVAD     RGB_VAD
#define KC_LMOD     RGB_MOD

#define KC_LOWER    LOWER
#define KC_RAISE    RAISE
#define KC_ADJUST   ADJUST
#define KC_NUMPAD   NUMPAD

// layer
#define KC_L_JPEN   LT(_LOWER, LALT(KC_GRV) )
#define KC_F_ESC    LT(_NUMR,  KC_ESC)
#define KC_AJ_SPC   LT(_ADJUST,  KC_SPC)

// shift_t
#define KC_S_TAB    LSFT_T(KC_TAB)
#define KC_S_ESC    LSFT_T(KC_ESC)
#define KC_S_MNS    SFT_T(KC_MINS)
#define KC_S_CLN    SFT_T(KC_COLN)
#define KC_S_DOT    SFT_T(KC_DOT)

// ctl_t
#define KC_C_BS     LCTL_T(KC_BSPC)
#define KC_C_TAB    CTL_T(KC_TAB)
#define KC_C_SPC    CTL_T(KC_SPC)
#define KC_C_JA     CTL_T(KC_LANG1)

// alt_t
#define KC_A_SL     ALT_T(KC_SLSH)
#define KC_A_DEL    ALT_T(KC_DEL)
#define KC_A_INS    ALT_T(KC_INS)
#define KC_A_NUM    ALT_T(KC_NUMPAD)


// ble
//#define KC_BLE       MO(_BLE)
#define KC_AD_WO_L   AD_WO_L
#define KC_BLE_DIS   BLE_DIS
#define KC_BLE_EN    BLE_EN
#define KC_USB_DIS   USB_DIS
#define KC_USB_EN    USB_EN
#define KC_ADV_ID0   ADV_ID0
#define KC_ADV_ID1   ADV_ID1
#define KC_ADV_ID2   ADV_ID2
#define KC_ADV_ID3   ADV_ID3
#define KC_ADV_ID4   ADV_ID4
#define KC_DEL_ID0   DEL_ID0
#define KC_DEL_ID1   DEL_ID1
#define KC_DEL_ID2   DEL_ID2
#define KC_DEL_ID3   DEL_ID3
#define KC_DEL_ID4   DEL_ID4
#define KC_ENT_DFU   ENT_DFU
#define KC_ENT_SLP   ENT_SLP
#define KC_BATT_LV   BATT_LV

//keymaps
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc( \
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,   DEL,\
      C_TAB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH, S_MNS,\
                                   A_INS, LOWER , C_SPC,    C_SPC,  RAISE,  A_NUM
  ),

  [_LOWER] = LAYOUT_kc(	\
  //,-----------------------------------------.                ,-----------------------------------------.
  //    ESC,     !,     @,     #,     $,     (,                      ),     %,     ^,     &,     *,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //  CTLTB,     `,     -,     =,     \,     [,                      ],     ',     ,,     .,     /,     ;,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //   LSFT,     ~,     _,     +,     |,     {,                      },     ",     <,     >,     ?, SFCLN,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  //                              ALINS,   SPC, LOWER,    RAISE,   ENT,  RALT
                              //`--------------------'  `--------------------'
        ESC,  EXLM,    AT,  HASH,   DLR,  LPRN,                   RPRN,  PERC,  CIRC,  AMPR,  ASTR,  BSPC,\
      C_TAB,   GRV,  MINS,   EQL,  BSLS,  LBRC,                   RBRC,  QUOT,  COMM,   DOT,  SLSH,  SCLN,\
       LSFT,  TILD,  UNDS,  PLUS,  PIPE,  LCBR,                   RCBR,  DQUO,  LABK,  RABK,  QUES, S_CLN,\
                                   A_INS, LOWER , C_SPC,    C_SPC,  RAISE,  A_NUM
  ),
  [_RAISE] = LAYOUT_kc( \
        ESC,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSPC,\
      C_TAB,     4,     5,     6,     0, XXXXX,                   LEFT,  DOWN,    UP, RIGHT,  HOME,   END,\
       LSFT,     7,     8,     9,  COMM,   DOT,                   PSCR,  LEFT,  DOWN, RIGHT,  PGDN,  PGUP,\
                                   A_INS, LOWER , C_SPC,    C_SPC,  RAISE,  A_NUM

 ),
  
  [_ADJUST] = LAYOUT_kc( \
        RST,  LRST, XXXXX, XXXXX, Q, AD_WO_L,                AD_WO_L, ADV_ID0 ,ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, \
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, BLE_EN ,                BLE_DIS, DEL_ID0 ,DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, \
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, USB_EN ,                USB_DIS, ENT_DFU, ENT_SLP, BATT_LV, XXXXX,   A  , \
                                   A_INS, LOWER , C_SPC,    C_SPC,  RAISE,  A_NUM
 ),

  [_NUMR] = LAYOUT_kc( \
      XXXXX,    F1,    F2,    F3,    F4,    F5,                  XXXXX, 7,     8,     9,   EQL,  XXXXX, \
      XXXXX,    F6,    F7,    F8,    F9,   F10,                   COMM, 4,     5,     6,  ASTR,   SLSH, \
      XXXXX,   F11,   F12, XXXXX, XXXXX, XXXXX,                    DOT, 1,     2,     3,  PLUS,   MINS, \
                                   A_INS, LOWER, C_SPC,    C_SPC,  RAISE,      0
 ),

};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
  layer_state_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
bool ble_ctrl( uint16_t keycode, keyrecord_t *record ){
	char str[16];
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case DEL_ID4:
      delete_bond_id(4);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }
  }
	return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  //char str[16];
  static uint16_t stored_keycode;
  bool is_tapped;
  bool is_toggled = false;

  uint16_t prev_keycode = stored_keycode;

  is_tapped = ( (!record->event.pressed) && (keycode == prev_keycode ));
  stored_keycode = keycode;

  switch ( keycode ) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        if( is_tapped ){
          SEND_STRING(SS_TAP(X_SPACE));
        }
      }
      update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
		if( is_tapped ){
		  SEND_STRING(SS_TAP(X_ENTER));
		}
      }
      update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case NUMPAD:
      if (record->event.pressed) {
      }else{
        is_toggled = !is_toggled;

        if( is_toggled ){
          layer_on(_NUMPAD);
        } else {
          layer_off(_NUMPADT);
        }
      }
      return false;
  }
  return true;
}


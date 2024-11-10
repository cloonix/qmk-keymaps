/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
  MAC01, // 0 - DIP switch left
  MACFN, // 1
  WIN01, // 2 - DIP switch right
  WINFN, // 3
  MAC02, // 4
  WIN02, // 5
};

// Tap Dance declarations
// enum {
//     TD_KC_GRV = 0,
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC01] = LAYOUT_iso_83(
 KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,            KC_MUTE,
 QK_LEAD,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,           KC_PGUP,
 KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                     KC_PGDN,
 MO(MAC02),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,            KC_HOME,
 KC_LSFT,    KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
 KC_LCTL,    KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, MO(MACFN),  KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RGHT),

[MACFN] = LAYOUT_iso_83(
 _______,  KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            RGB_TOG,
 _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
 RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
 _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
 _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
 _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[MAC02] = LAYOUT_iso_83(
 _______,  _______,        _______,       _______,       _______,         _______,     _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,                    _______,
 _______,  LCAG(KC_1),     LCAG(KC_2),    LCAG(KC_3),     LCAG(KC_4),     LCAG(KC_5),     _______,  _______,  _______,  _______,    _______,  _______,  _______,  QK_BOOT,                    _______,
 _______,  LCAG(KC_Q),     LCTL(KC_UP),   LCAG(KC_E),     _______,        LCAG(KC_T),  _______,  _______,  _______,  _______,    _______,  _______,  _______,                              _______,
 _______,  LCTL(KC_LEFT),  LCTL(KC_DOWN), LCTL(KC_RIGHT), LCAG(KC_F),     _______,     _______,  _______,  _______,  LCAG(KC_L), _______,  _______,  _______,  _______,                    _______,
 _______,  _______,        LCAG(KC_LEFT), LCA(KC_ENT),    LCAG(KC_RIGHT), LCAG(KC_V),  _______,  _______,  _______,  _______,    _______,  _______,            _______,      LCA(KC_UP),
 _______,  _______,        _______,                                                    _______,                                  _______,  _______,  _______,  LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_RIGHT)
 ),

[WIN01] = LAYOUT_iso_83(
 KC_ESC,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_DEL,             KC_MUTE,
 QK_LEAD,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,            KC_PGUP,
 KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,                      KC_PGDN,
 MO(WIN02),   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,   KC_NUHS,  KC_ENT,             KC_HOME,
 KC_LSFT,     KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,  KC_UP,
 KC_LCTL,     KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WINFN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WINFN] = LAYOUT_iso_83(
 _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            RGB_TOG,
 _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
 RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
 _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
 _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
 _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[WIN02] = LAYOUT_iso_83(
 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,            _______,
 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
 _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC01] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MACFN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MAC02] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [WIN01] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WINFN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN02] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_KC_GRV] = ACTION_TAP_DANCE_LAYER_TOGGLE(QK_LEAD, WIN_01),
// };

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

  bool did_leader_succeed = false;

  if (leader_sequence_one_key(KC_1)) {
    layer_move(MAC01);
    did_leader_succeed = true;
  }
  
  if (leader_sequence_one_key(KC_2)) {
    layer_move(WIN01);
    did_leader_succeed = true;
  }
  
  if (!did_leader_succeed) {
    tap_code(KC_GRV);
  }
}

// RGB modifications
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i < led_max; i++) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
      case 2: // WIN01
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
      case 1: // MACFN
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
      default: // MAC01
        break;
      }
    }
  return false;
}
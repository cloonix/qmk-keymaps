/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off
enum layers{
  MAC01, // 0 - DIP switch left
  MACFN, // 1
  WIN01, // 2 - DIP switch right
  WINFN, // 3
  MAC02, // 4
  WIN02, // 5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[MAC01] = LAYOUT_tkl_iso(
KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12,                KC_TRNS,   LSG(KC_M), RGB_TOG,
KC_TRNS,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,     KC_EQL,      KC_BSPC,  KC_INS,    KC_HOME,   KC_PGUP,
KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,               KC_DEL,    KC_END,    KC_PGDN,
MO(MAC02), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,     KC_NUHS,     KC_ENT,
KC_LSFT,   KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                  KC_RSFT,             KC_UP,
KC_LCTL,   KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,    MO(MACFN),   KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
),

[MACFN] = LAYOUT_tkl_iso(
_______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,           _______,  _______,  RGB_TOG,
_______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______, _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
_______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG, _______,  _______,  _______,  _______,            _______,            _______,
_______,  _______,  _______,                                _______,                               _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[WIN02] = LAYOUT_tkl_iso(
DM_RSTP, DM_REC1,        DM_PLY1,             DM_REC2,        DM_PLY2,     DB_TOGG,     _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_PWR,   KC_WAKE,  KC_SLEP,
KC_NUM,  _______,        _______,             _______,        _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,  _______,
_______, _______,        C(S(KC_W)),          C(S(KC_E)),     C(S(KC_R)),  C(S(KC_T)),  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
_______, C(G(KC_LEFT)),  C(S(KC_CAPS_LOCK)),  C(G(KC_RIGHT)), _______,     C(S(KC_G)),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______, _______,        _______,             _______,        _______,     _______,     KC_WHOM,  _______,  KC_MAIL,  _______,  _______,  _______,            _______,            _______,
_______, _______,        _______,                                                       _______,                      _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[WIN01] = LAYOUT_tkl_iso(
KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                   KC_PSCR,  KC_MUTE, RGB_TOG,
KC_TRNS,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,      KC_INS,   KC_HOME, KC_PGUP,
KC_TRNS,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                  KC_DEL,   KC_END,  KC_PGDN,
KC_TRNS,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
KC_LSFT, KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,                KC_UP,
KC_LCTL, KC_TRNS,    KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(WINFN),  KC_RCTL,      KC_LEFT,  KC_DOWN,  KC_RGHT
),

[WINFN] = LAYOUT_tkl_iso(
_______,  KC_BRID,       KC_BRIU,  KC_TASK,        KC_FILE,  RGB_SPI,  RGB_SPD,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            RGB_RMOD, RGB_MOD,  RGB_TOG,
_______,  BT_HST1,       BT_HST2,  BT_HST3,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_VAI,  RGB_HUI,  RGB_SAI,
_______,  _______,       _______,  _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_VAD,  RGB_HUD,  RGB_SAD,
_______,  _______,       _______,  _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,       _______,  _______,        _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
_______,  _______,       _______,                                      _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[MAC02] = LAYOUT_tkl_iso(
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,            _______,       _______,  _______,
_______,  LCAG(KC_1),    LCAG(KC_2),    LCAG(KC_3),     LCAG(KC_4),     LCAG(KC_5),   _______, _______,  _______,  _______,    _______,  _______,  _______,  QK_BOOT,  LCA(KC_U),     _______,  LCA(KC_I),
_______,  LCAG(KC_Q),    LCTL(KC_UP),   LCAG(KC_E),     _______,        LCAG(KC_T),   _______, _______,  _______,  _______,    _______,  _______,  _______,            LCA(KC_J),     _______,  LCA(KC_K),
_______,  LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), LCAG(KC_F),     _______,      _______, _______,  _______,  LCAG(KC_L), _______,  _______,  _______,  _______,
_______,  _______,       LCAG(KC_LEFT), LCA(KC_ENT),    LCAG(KC_RIGHT), LCAG(KC_V),   _______, _______,  _______,  _______,    _______,  _______,            _______,                 LCA(KC_UP),
_______,  _______,       _______,                                                     _______,                                 _______,  _______,  _______,  _______,  LCA(KC_LEFT),  LCA(KC_DOWN), LCA(KC_RIGHT)
),

};

// RGB modifications
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (get_highest_layer(layer_state) > 0) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t i = g_led_config.matrix_co[row][col];

        // Set the color of the key with i == 0 based on the layer value
        if (i == 0) {
          switch (layer) {
            case 0:
              rgb_matrix_set_color(i, RGB_WHITE);
              break;
            case 1:
              rgb_matrix_set_color(i, RGB_BLUE);
              break;
            case 2:
              rgb_matrix_set_color(i, RGB_ORANGE);
              break;
            case 3:
              rgb_matrix_set_color(i, RGB_BLUE);
              break;
            case 4:
              rgb_matrix_set_color(i, RGB_GREEN);
              break;
            case 5:
              rgb_matrix_set_color(i, RGB_GREEN);
              break;
            default:
              rgb_matrix_set_color(i, RGB_WHITE);
              break;
          }
        } else {
          switch(layer) {
            case 1: 
            case 3: 
            case 4: 
            case 5: 
            case 6: 
            case 7: 
              if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                  rgb_matrix_set_color(i, RGB_PURPLE);
              } else {
                  rgb_matrix_set_color(i, RGB_OFF);
              }
              break;
            case 2:
            default: // WIN01
              break;
          }
        }
      }
    }
  } else {
    // Ensure the key 'i' is set to white when in the default layer state
    rgb_matrix_set_color(0, RGB_WHITE);
  }
  return false;
}
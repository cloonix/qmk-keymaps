#include QMK_KEYBOARD_H

enum layers{
  MAC_BASE, // 0 - DIP switch down
  MAC_FN, // 1
  WIN_BASE, // 2 - DIP switch up
  WIN_FN, // 3
  MAC_FN2, // 4
  WIN_FN2, // 5
  GAME // 6
};

enum td_keycodes {
  PRINT,
  SPACE,
  CAPS_KEY
};

typedef enum {
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP
} td_state_t;

static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void print_finished(tap_dance_state_t *state, void *user_data);
void print_reset(tap_dance_state_t *state, void *user_data);
void caps_finished(tap_dance_state_t *state, void *user_data);
void caps_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_tkl_iso(
KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,               TD(PRINT),  KC_MUTE,  RGB_MOD,
QK_LEAD,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,     KC_HOME,  KC_PGUP,
KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,     KC_END,   KC_PGDN,
TD(CAPS_KEY),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
KC_LSFT,         KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
KC_LCTL,         KC_LOPTN, KC_LCMD,                                TD(SPACE),                              KC_RCMD,  KC_ROPTN, MO(MAC_FN), KC_RCTL,  KC_LEFT,    KC_DOWN,  KC_RGHT
),

[MAC_FN] = LAYOUT_tkl_iso(
_______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  _______,  RGB_TOG,
_______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,  _______,
RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
_______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
_______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[WIN_BASE] = LAYOUT_tkl_iso(
KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             TD(PRINT),  KC_MUTE,  RGB_MOD,
QK_LEAD,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,     KC_HOME,  KC_PGUP,
KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,     KC_END,   KC_PGDN,
LCAG_T(KC_CAPS), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
KC_LSFT,         KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
KC_LCTL,         KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
),

[WIN_FN] = LAYOUT_tkl_iso(
_______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  _______,  RGB_TOG,
_______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,  _______,
RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
_______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
_______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[MAC_FN2] = LAYOUT_tkl_iso(
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,            _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,            _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,            _______,                 _______,
_______,  _______,       _______,                                                     _______,                                 _______,  _______,  _______,  _______,  _______,       _______,  _______
),

[WIN_FN2] = LAYOUT_tkl_iso(
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,            _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,            _______,       _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,  _______,  _______,
_______,  _______,       _______,       _______,        _______,        _______,      _______, _______,  _______,  _______,    _______,  _______,            _______,                 _______,
_______,  _______,       _______,                                                     _______,                                 _______,  _______,  _______,  _______,  _______,       _______,  _______
),

[GAME] = LAYOUT_tkl_iso(
KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             TD(PRINT),  KC_MUTE,  RGB_MOD,
QK_LEAD,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,     KC_HOME,  KC_PGUP,
KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,     KC_END,   KC_PGDN,
KC_NO,           KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
KC_LSFT,         KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
KC_LCTL,         KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
),

};

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Tap dances
// Print Screen

void print_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_PSCR);
            break;
        case TD_DOUBLE_TAP: 
            register_mods(MOD_BIT(KC_LCTL));
            register_code16(KC_PSCR);
            break;
        default:
            break;
    }
}

void print_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_PSCR);
            break;
        case TD_DOUBLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code16(KC_PSCR);
            break;
        default:
            break;
    }
}

void space_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_SPC);
            break;
        case TD_SINGLE_HOLD: 
            register_mods(MOD_BIT(KC_LCMD));
            register_code16(KC_SPC);
            break;
        default:
            break;
    }
}

void space_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCMD));
            unregister_code16(KC_SPC);
            break;
        default:
            break;
    }
}

// CAPS key tap dance implementation
void caps_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            // On tap: Enable one-shot modifiers CMD+Option+Shift
            set_oneshot_mods(MOD_BIT(KC_LCMD) | MOD_BIT(KC_LOPT) | MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
            // On hold: Enable Ctrl+Option+CMD
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LOPT) | MOD_BIT(KC_LCMD));
            break;
        default:
            break;
    }
}

void caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            // One-shot modifiers clear themselves after next key press
            break;
        case TD_SINGLE_HOLD:
            // Release the held modifiers
            unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LOPT) | MOD_BIT(KC_LCMD));
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [PRINT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, print_finished, print_reset),
    [SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset),
    [CAPS_KEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

  bool did_leader_succeed = false;

  if (leader_sequence_one_key(KC_1)) {
    layer_move(MAC_BASE);
    did_leader_succeed = true;
  }
  
  if (leader_sequence_one_key(KC_2)) {
    layer_move(WIN_BASE);
    did_leader_succeed = true;
  }
  
  if (leader_sequence_one_key(KC_3)) {
    layer_move(GAME);
    did_leader_succeed = true;
  }
  
  if (!did_leader_succeed) {
    tap_code(KC_GRV);
  }
}

// RGB modifications
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (get_highest_layer(layer_state) >= 0) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t i = g_led_config.matrix_co[row][col];

        // Set the color of the key with i == 0 based on the layer value
        if (i == 0) {
          switch (layer) {
            case 0:
            default:
              rgb_matrix_set_color(i, RGB_GREEN);
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
              rgb_matrix_set_color(i, RGB_WHITE);
              break;
            case 6:
              rgb_matrix_set_color(i, RGB_RED);
              break;
           }
/*          
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
*/
        } 
      }
    }
  }
  return false;
}
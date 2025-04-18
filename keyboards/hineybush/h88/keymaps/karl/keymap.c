/* Copyright 2019 Josh Hinnebusch

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

//Tap Dance Declarations
enum {
  MENU,
};

void td_menu_selct (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1 && !state->pressed) {
    SEND_STRING(SS_TAP(X_APPLICATION));
    reset_tap_dance(state);
  } else if (state->count == 2 && !state->pressed) {
    SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_END) SS_UP(X_LEFT_SHIFT));
//    SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_END));
    reset_tap_dance(state);
  } else {
    // hard reset
    state->count = 0;
    state->interrupted = false;
    state->finished = false;
  }
}

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [MENU]  = ACTION_TAP_DANCE_FN(td_menu_selct),
};
// end TD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_tkl_ansi_wkl(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,     TD(MENU),                    MO(1),   KC_SCRL, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,                 KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                 KC_DEL,  KC_END,  KC_PGDN,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                                                  KC_UP,
    KC_LCTL, KC_LALT,                   KC_SPC,                                      KC_RGUI,           KC_RCTL,                                         KC_LEFT, KC_DOWN, KC_RGHT),

  [1] = LAYOUT_tkl_ansi_wkl(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS,               BL_TOGG, BL_DOWN,  BL_UP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,               KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,               KC_MPLY, KC_MNXT, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS,
    KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS,          KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}



/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "action_layer.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
};

//Tap Dance Declarations
enum td_codes {
  NAV,
  RAISE,
  LOWER,
  QUERY,
  MENU
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        TD(MENU),  TD(MENU), KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_HOME,   KC_PGUP,  KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_END,    KC_PGDN,  KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
                                   KC_LGUI, KC_LALT, TD(LOWER),   TD(NAV),   KC_SPC,   TD(RAISE),   KC_TAB,  KC_DEL
    ),

    [_NAV] = LAYOUT(
        _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______, _______, _______, RGUI(KC_LEFT), RGUI(KC_DOWN), RGUI(KC_UP), RGUI(KC_RGHT), _______, _______,
        _______, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGUP, _______,
        _______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______, _______, _______, RCTL(RGUI(KC_LEFT)), RCTL(RGUI(KC_DOWN)), RCTL(RGUI(KC_UP)), RCTL(RGUI(KC_RGHT)), KC_PGDN, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),




};

// Tap Dance for Tab / Nav layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_nav_state_t;
static void ang_tap_dance_nav_finished (tap_dance_state_t *state, void *user_data) {
  td_nav_state_t *td_nav = (td_nav_state_t *) user_data;
  if (td_nav->sticky) {
    td_nav->sticky = false;
    td_nav->layer_toggle = false;
    layer_off (_NAV);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_NAV);
    td_nav->sticky = false;
    td_nav->layer_toggle = false;
  } else {
    td_nav->layer_toggle = true;
    layer_on (_NAV);
    td_nav->sticky = (state->count == 2);
  }
}
static void ang_tap_dance_nav_reset (tap_dance_state_t *state, void *user_data) {
  td_nav_state_t *td_nav = (td_nav_state_t *) user_data;
  if (!td_nav->sticky) {
    layer_off (_NAV);
  }
}

// Tap Dance for Raise layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_raise_state_t;
static void ang_tap_dance_raise_finished (tap_dance_state_t *state, void *user_data) {
  td_raise_state_t *td_raise = (td_raise_state_t *) user_data;
  if (td_raise->sticky) {
    td_raise->sticky = false;
    td_raise->layer_toggle = false;
    layer_off (_RAISE);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_RAISE);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    td_raise->sticky = false;
    td_raise->layer_toggle = false;
  } else {
    td_raise->layer_toggle = true;
    layer_on(_RAISE);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    td_raise->sticky = (state->count == 2);
  }
}
static void ang_tap_dance_raise_reset (tap_dance_state_t *state, void *user_data) {
  td_raise_state_t *td_raise = (td_raise_state_t *) user_data;
  if (!td_raise->layer_toggle || !td_raise->sticky) {
    layer_off(_RAISE);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
  }
}

// Tap Dance for Lower layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_lower_state_t;
static void ang_tap_dance_lower_finished (tap_dance_state_t *state, void *user_data) {
  td_lower_state_t *td_lower = (td_lower_state_t *) user_data;
  if (td_lower->sticky) {
    td_lower->sticky = false;
    td_lower->layer_toggle = false;
    layer_off (_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    td_lower->sticky = false;
    td_lower->layer_toggle = false;
  } else {
    td_lower->layer_toggle = true;
    layer_on(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    td_lower->sticky = (state->count == 2);
  }
}
static void ang_tap_dance_lower_reset (tap_dance_state_t *state, void *user_data) {
  td_lower_state_t *td_lower = (td_lower_state_t *) user_data;
  if (!td_lower->layer_toggle || !td_lower->sticky) {
    layer_off(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
  }
}

// Tap Dance for Menu layer functionality
void td_menu_selct (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1 && !state->pressed) {
    SEND_STRING(SS_TAP(X_APP));
    reset_tap_dance(state);
  } else if (state->count == 2 && !state->pressed) {
    SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT));
    reset_tap_dance(state);
  } else {
    // hard reset
    state->count = 0;
    state->interrupted = false;
    state->finished = false;
  }
};


//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [NAV]  = {
     .fn = { NULL, ang_tap_dance_nav_finished, ang_tap_dance_nav_reset },
     .user_data = (void *)&((td_nav_state_t) { false, false })
   },
  [RAISE]  = {
     .fn = { NULL, ang_tap_dance_raise_finished, ang_tap_dance_raise_reset },
     .user_data = (void *)&((td_raise_state_t) { false, false })
   },
  [LOWER]  = {
     .fn = { NULL, ang_tap_dance_lower_finished, ang_tap_dance_lower_reset },
     .user_data = (void *)&((td_lower_state_t) { false, false })
   },
  [MENU]  = ACTION_TAP_DANCE_FN(td_menu_selct)
};
// end TD

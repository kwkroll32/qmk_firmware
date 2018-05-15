/* Copyright 2015-2017 Jack Humbert
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

#include "contra.h"
#include "action_layer.h"

#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _QUERY,
  _ECLIPSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QSEL,
  QWHERE,
  QIN,
  QEQUAL,
  QAND,
  QLIKE,
  AEPDOC,
  AEPVLM,
  ROBJID,
  DESCR,
  LTYPE

};

//Tap Dance Declarations
enum td_codes {
  NAV,
  RAISE,
  LOWER,
  QUERY,
  ECLIPSE,
  MENU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | gEsc |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | MENU |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Tab/Fn|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |ShfGui|Lower |BkSpac|Space |Raise | Nav  | Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GESC,        KC_Q,    KC_W,    KC_E,           KC_R,        KC_T,     KC_Y,    KC_U,        KC_I,     KC_O,    KC_P,    TD(MENU)     },
  {TD(NAV),        KC_A,    KC_S,    KC_D,           KC_F,        KC_G,     KC_H,    KC_J,        KC_K,     KC_L,    KC_SCLN, KC_QUOT      },
  {KC_LSFT,        KC_Z,    KC_X,    KC_C,           KC_V,        KC_B,     KC_N,    KC_M,        KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_ENT)},
  {CTL_T(KC_HOME), KC_LGUI, KC_LALT, LGUI(KC_LSFT),  TD(LOWER),   KC_BSPC,  KC_SPC,  TD(RAISE),   TD(NAV),  KC_RALT, KC_RGUI, CTL_T(KC_END)}
},

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |GUI_1 |GUI_2 |GUI_3 |      |      | GUIL | GUID | GUIU | GUIR |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |GUI_4 |GUI_5 |GUI_6 |      |      | Left | Down |  Up  | Rght |Pg Up |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |GUI_7 |GUI_8 |GUI_9 |      |      | GC_L | GC_D | GC_U | GC_R |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = {
  {_______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______, RGUI(KC_LEFT),       RGUI(KC_DOWN),       RGUI(KC_UP),       RGUI(KC_RGHT),       _______, _______},
  {_______, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______, KC_LEFT,             KC_DOWN,             KC_UP,             KC_RGHT,             KC_PGUP, _______},
  {_______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______, RCTL(RGUI(KC_LEFT)), RCTL(RGUI(KC_DOWN)), RCTL(RGUI(KC_UP)), RCTL(RGUI(KC_RGHT)), KC_PGDN, _______},
  {_______, _______,    _______,    _______,    _______, _______, _______,             _______,             _______,           _______,             _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL },
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |RGBTOG|RGBMOD|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______,_______,  _______, _______, _______, _______, _______, QWERTY,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______,TD(QUERY),_______, _______, _______, _______, _______, _______, _______, _______}
},

/* Query
 * ,-----------------------------------------------------------------------------------.
 * |QWERTY|      |where |equals|robjid|listyp|      |      |  in  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |aepdoc|select|descrp|      |      |      |      |      | like |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |aepvlm|      | and  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QUERY] = {
  {QWERTY,  _______, QWHERE,  QEQUAL,  ROBJID,  LTYPE,   _______, _______, QIN,     _______, _______, _______},
  {_______, AEPDOC,  QSEL,    DESCR,   _______, _______, _______, _______, _______, QLIKE,   _______, _______},
  {_______, _______, _______, _______, AEPVLM,  _______, QAND,    _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Eclipse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ECLIPSE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


};

// Tap Dance for Tab / Nav layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_nav_state_t;

static void ang_tap_dance_nav_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_nav_state_t *td_nav = (td_nav_state_t *) user_data;
  if (td_nav->sticky) {
    td_nav->sticky = false;
    td_nav->layer_toggle = false;
    layer_off (_NAV);
    update_tri_layer(_LOWER, _NAV, _QUERY);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    register_code (KC_TAB);
    td_nav->sticky = false;
    td_nav->layer_toggle = false;
  } else {
    td_nav->layer_toggle = true;
    layer_on (_NAV);
    update_tri_layer(_LOWER, _NAV, _QUERY);
    td_nav->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_nav_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_nav_state_t *td_nav = (td_nav_state_t *) user_data;
  if (!td_nav->layer_toggle)
    unregister_code (KC_TAB);
  if (!td_nav->sticky)
    layer_off (_NAV);
    update_tri_layer(_LOWER, _NAV, _QUERY);
}

// Tap Dance for Raise layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_raise_state_t;

static void ang_tap_dance_raise_finished (qk_tap_dance_state_t *state, void *user_data) {
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

static void ang_tap_dance_raise_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_raise_state_t *td_raise = (td_raise_state_t *) user_data;
  if (!td_raise->layer_toggle || !td_raise->sticky)
    layer_off(_RAISE);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
}

// Tap Dance for Lower layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_lower_state_t;

static void ang_tap_dance_lower_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_lower_state_t *td_lower = (td_lower_state_t *) user_data;
  if (td_lower->sticky) {
    td_lower->sticky = false;
    td_lower->layer_toggle = false;
    layer_off (_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    update_tri_layer(_LOWER, _NAV, _QUERY);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    update_tri_layer(_LOWER, _NAV, _QUERY);
    td_lower->sticky = false;
    td_lower->layer_toggle = false;
  } else {
    td_lower->layer_toggle = true;
    layer_on(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    update_tri_layer(_LOWER, _NAV, _QUERY);
    td_lower->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_lower_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_lower_state_t *td_lower = (td_lower_state_t *) user_data;
  if (!td_lower->layer_toggle || !td_lower->sticky)
    layer_off(_LOWER);
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    update_tri_layer(_LOWER, _NAV, _QUERY);
}

// Tap Dance for Query layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_query_state_t;

static void ang_tap_dance_query_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_query_state_t *td_query = (td_query_state_t *) user_data;
  if (td_query->sticky) {
    td_query->sticky = false;
    td_query->layer_toggle = false;
    layer_off (_QUERY);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_QUERY);
    td_query->sticky = false;
    td_query->layer_toggle = false;
  } else {
    td_query->layer_toggle = true;
    layer_on(_QUERY);
    td_query->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_query_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_query_state_t *td_query = (td_query_state_t *) user_data;
  if (!td_query->layer_toggle || !td_query->sticky)
    layer_off(_QUERY);
}

// Tap Dance for Eclipse layer functionality
typedef struct {
  bool layer_toggle;
  bool sticky;
} td_eclipse_state_t;

static void ang_tap_dance_eclipse_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_eclipse_state_t *td_eclipse = (td_eclipse_state_t *) user_data;
  if (td_eclipse->sticky) {
    td_eclipse->sticky = false;
    td_eclipse->layer_toggle = false;
    layer_off (_ECLIPSE);
    return;
  }
  if (state->count == 1 && !state->pressed) {
    layer_on(_ECLIPSE);
    td_eclipse->sticky = false;
    td_eclipse->layer_toggle = false;
  } else {
    td_eclipse->layer_toggle = true;
    layer_on(_ECLIPSE);
    td_eclipse->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_eclipse_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_eclipse_state_t *td_eclipse = (td_eclipse_state_t *) user_data;
  if (!td_eclipse->layer_toggle || !td_eclipse->sticky)
    layer_off(_ECLIPSE);
}

void td_menu_selct (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1 && !state->pressed) {
    SEND_STRING(SS_TAP(X_APPLICATION));
    reset_tap_dance(state);
  } else if (state->count == 2 && !state->pressed) {
    SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT));
    reset_tap_dance(state);
  } else {
    // hard reset
    state->count = 0;
    state->interrupted = false;
    state->finished = false;
  }
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
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
  [QUERY]  = {
     .fn = { NULL, ang_tap_dance_query_finished, ang_tap_dance_query_reset },
     .user_data = (void *)&((td_query_state_t) { false, false })
   },
  [ECLIPSE]  = {
     .fn = { NULL, ang_tap_dance_eclipse_finished, ang_tap_dance_eclipse_reset },
     .user_data = (void *)&((td_eclipse_state_t) { false, false })
   },
  [MENU]  = ACTION_TAP_DANCE_FN(td_menu_selct)
};
// end TD

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case QWERTY:
        layer_off(_QUERY);
        set_single_persistent_default_layer(_QWERTY);
        return false;
        break;

      // query layer macros
      case QSEL:
        SEND_STRING("SELECT * from  ");
        SEND_STRING(SS_TAP(X_LEFT));
        return false;
        break;
      case QWHERE:
        SEND_STRING(" WHERE  ");
        SEND_STRING(SS_TAP(X_LEFT));
        return false;
        break;
      case QIN:
        SEND_STRING(" IN ('',) ");
        SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false;
        break;
      case QEQUAL:
        SEND_STRING(" = '' ");
        SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false;
        break;
      case QAND:
        SEND_STRING(" AND ");
        return false;
        break;
      case QLIKE:
        SEND_STRING(" LIKE '' ");
        SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false;
        break;

      case AEPDOC:
        SEND_STRING("aep_document");
        SEND_STRING(SS_TAP(X_END));
        return false;
        break;
      case AEPVLM:
        SEND_STRING("aep_value_list_item");
        SEND_STRING(SS_TAP(X_END));
        return false;
        break;
      case DESCR:
        SEND_STRING("description");
        SEND_STRING(SS_TAP(X_END));
        return false;
        break;
      case LTYPE:
        SEND_STRING("list_type");
        SEND_STRING(SS_TAP(X_END));
        return false;
        break;
      case ROBJID:
        SEND_STRING("r_object_id");
        SEND_STRING(SS_TAP(X_END));
        return false;
        break;



    }
  }
  return true;
}

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum ergodox_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST,
  _QUERY,
};


enum custom_keycodes {
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
  MENU
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   =   |  0  |  2  |  3  |  4  |  5  | ESC |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   \   |  Q  |  W  |  E  |  R  |  T  |LCK-1|
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |  TAB  |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+ f1  |
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |LCTRL|LGUI |LALT |ShGui|Lower|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |LCTRL| LALT|
 *                                  +-----+-----+-----+
 *                                  |     |     | HOME|
 *                                  |BKSPC| DEL +-----+
 *                                  |     |     | END |
 *                                  +-----+-----+-----+
 */
        KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_ESC,
        KC_BSLS, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(_NAV),
        TD(NAV),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_NAV),
        CTL_T(KC_HOME), KC_LGUI, KC_LALT, LGUI(KC_LSFT), TD(LOWER),
                                                      KC_LCTL, KC_LALT,
                                                               KC_HOME,
                                             KC_BSPC, KC_DEL,  KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |LCK-2|  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |  [  |  Y  |  U  |  I  |  O  |  P  |   ]   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
 *        | f1  +-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |RAISE|Nav  |RALT |RGUI |RCRTL|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    | RALT|RCTRL|
 *    +-----+-----+-----+
 *    | PGUP|     |     |
 *    +-----+ ENT | SPC |
 *    | PGDN|     |     |
 *    +-----+-----+-----+
 */
             TG(_LOWER),  KC_6,   KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
             KC_LBRC, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,     KC_RBRC,
                      KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
             MO(_NAV),  KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              TD(RAISE), TD(NAV), KC_RALT,  KC_RGUI, CTL_T(KC_END),
             KC_RALT, TD(MENU),
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),

[_NAV] = LAYOUT_ergodox( // layer 1 : function layers
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       | f1  | f2  | f3  | f4  | f5  | f11 |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       | g1  | g2  | g3  |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | g4  | g5  | g6  |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | g7  | g8  | g9  |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       KC_TRNS, LGUI(KC_1),LGUI(KC_2),LGUI(KC_3), KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_TRNS, KC_TRNS,
       KC_TRNS, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | f12 | f6  | f7  | f8  | f9  | f10 |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     | GUIL| GUID| GUIU| GUIR|     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+ Left| Down|  Up |Right|pg up|       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     | GC_L|GC_D |GC_U |GC_R |pg dn|       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, RGUI(KC_LEFT), RGUI(KC_DOWN),RGUI(KC_UP), RGUI(KC_RGHT), KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGUP, KC_TRNS,
       KC_TRNS, RCTL(RGUI(KC_LEFT)), RCTL(RGUI(KC_DOWN)), RCTL(RGUI(KC_UP)), RCTL(RGUI(KC_RGHT)), KC_PGDN, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[_LOWER] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   ~   |     |     |     |     |     |FLASH|
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  !  |  @  |  #  |  $  |  %  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | F1  | F2  | F3  | F4  | F5  +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | F7  | F8  | F9  | F10 | F11 |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TILD,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_TRNS,
       KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
       KC_TRNS, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |FLASH|     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |  ^  |  &  |  *  |  (  |  )  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+ F6  |  _  |  +  |  {  |  }  |   |   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     | F12 |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | P0  |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       RESET,    KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
       KC_TRNS,  KC_CIRC, KC_AMPR,    KC_ASTR,     KC_LPRN,        KC_RPRN,     KC_TRNS,
                 KC_F6,   KC_UNDS,    KC_PLUS,     KC_LCBR,        KC_RCBR,     KC_PIPE,
       KC_TRNS,  KC_F12,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_0
),

[_RAISE] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   `   |     |     |     |     |     |FLASH|
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  1  |  2  |  3  |  4  |  5  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | F1  | F2  | F3  | F4  | F5  +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       | F7  | F8  | F9  | F10 | F11 |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_TRNS,
       KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
       KC_TRNS, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |FLASH|     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |  6  |  7  |  8  |  9  |  0  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+ F6  |  -  |  =  |  [  |  ]  |   \   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     | F12 |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       RESET,    KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
       KC_TRNS,  KC_6,    KC_7,       KC_8,        KC_9,           KC_0,        KC_TRNS,
                 KC_F6,   KC_MINS,    KC_EQL,      KC_LBRC,        KC_RBRC,     KC_BSLS,
       KC_TRNS,  KC_F12,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[_QUERY] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |QWERTY |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |where|equal|r_id |lsttp|     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |aepdo|selct|descr|     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     | vlm |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       QWERTY,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, QWHERE,  QEQUAL,  ROBJID,  LTYPE,   KC_TRNS,
       KC_TRNS, AEPDOC,  QSEL,    DESCR,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AEPVLM,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     | in  |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |like |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     | and |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,    QIN,         KC_TRNS,        KC_TRNS,     KC_TRNS,
                 KC_TRNS, KC_TRNS,    KC_TRNS,     QLIKE,          KC_TRNS,     KC_TRNS,
       KC_TRNS,  QAND,    KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),




};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
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
        SEND_STRING(" LIKE '%%' ");
        SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

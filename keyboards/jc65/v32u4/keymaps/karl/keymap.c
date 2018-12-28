#include "v32u4.h"


enum layers{
  BASE,    // default layer
  FN_1,    // function layer 1
  LEDS     // underglow controls
};

enum keycodes {
  DEL_LN
};

//Tap Dance Declarations
enum td_codes {
  TD_MENU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default QWERTY layout
    ,-----------------------------------------------------------------------------------------------.
    |gesc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  | menu|
    |-----------------------------------------------------------------------------------------------|
    |  tab  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |  backsp | del |
    |-----------------------------------------------------------------------------------------------|
    |  FN_1   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |   enter     | pgup|
    |-----------------------------------------------------------------------------------------------|
    |  shift    |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |  shift    |  up |guipd|
    |-----------------------------------------------------------------------------------------------|
    | c/hom| gui |  alt |                  space                   | alt  | c/end | left| down|right|
    '-----------------------------------------------------------------------------------------------'

*/
  [BASE] = LAYOUT(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, TD(TD_MENU),
      KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,      KC_BSPC , KC_DEL,
      MO(1),     KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,            KC_ENT , KC_PGUP,
      KC_LSFT,KC_NO,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT, KC_UP , RGUI_T(KC_PGDN),
      CTL_T(KC_HOME), KC_LGUI, KC_LALT, KC_SPACE, KC_SPACE , KC_SPACE,   KC_RALT,KC_NO,CTL_T(KC_END), KC_LEFT,KC_DOWN, KC_RGHT
      ),



/* Function layer 1
    ,-----------------------------------------------------------------------------------------------.
    |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |
    |-----------------------------------------------------------------------------------------------|
    |       |     |  up |     |     |     |     |     |     |     |     |home | end | delete  |DE_LN|
    |-----------------------------------------------------------------------------------------------|
    |  FN_1   | left| down|right|     |     | left| down|  up |right|     |     |             | volu|
    |-----------------------------------------------------------------------------------------------|
    |           |     |     |     |     |     |     |     | pgdn| pgup|     |           | pgup| vold|
    |-----------------------------------------------------------------------------------------------|
    |      |     |      |                                          |      |  FN_2 | home| pgdn| end |
    '-----------------------------------------------------------------------------------------------'

*/
  [FN_1] = LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_DEL, DEL_LN,
      MO(1), KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_PGUP, KC_VOLD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_HOME, KC_PGDN, KC_END
      ),


/* Function layer for underglow LED controls
    ,-----------------------------------------------------------------------------------------------.
    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |flash|
    |-----------------------------------------------------------------------------------------------|
    |       |     |     |     |     |onoff|     |     |     |     |     |     |     |         |     |
    |-----------------------------------------------------------------------------------------------|
    |  FN_1   |sat d|sat u|     |     |hue d|hue u|     |     |     |     |     |             |     |
    |-----------------------------------------------------------------------------------------------|
    |           |     |     |     |dark |brite|     |mode-|mode+|     |     |           |     |     |
    |-----------------------------------------------------------------------------------------------|
    |      |     |      |                                          |      |  FN_2 |     |     |     |
    '-----------------------------------------------------------------------------------------------'

*/
  [LEDS] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      MO(1), RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, KC_TRNS, RGB_RMOD, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS, KC_TRNS, KC_TRNS
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case DEL_LN:
              SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT)SS_TAP(X_DELETE));
              break;

            default:
              break;
        return false;
        }
    }
    return true;
};

void td_menu_selct (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_APP);
    unregister_code(KC_APP);
  } else {
    SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT));
    reset_tap_dance(state);
  }
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MENU]  = ACTION_TAP_DANCE_FN(td_menu_selct)
// Other declarations would go here, separated by commas, if you have them
};


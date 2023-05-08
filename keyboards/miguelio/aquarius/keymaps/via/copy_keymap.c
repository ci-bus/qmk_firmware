#include QMK_KEYBOARD_H
// #include "raw_hid.h"

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0| ? | ¿ |Backspa |HOM|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     | END|
   * |-------------------------------------------------------|   |----|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ñ|  {| } |Ent|SUPR|
   * |----------------------------------------------------------------|
   * |Shif| <>|  Z|  X|  C|  V|  B|  N|  M| ,;| .:|   Shift  | Up| - _|
   * |----------------------------------------------------------------|
   * |Ctrl |Win |Alt |        Space          |Alt | FN|   Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [_BL] = LAYOUT_65_iso(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_DEL, \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_RSFT,    KC_UP,   KC_SLSH, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FL),          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Keymap _FL1: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   SCR-|WAKE|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   | SCR+| PWD|
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |    |   |SLEP|
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |    |   |   |     |VL+|    |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |                       |Alt|        |MUT|VL-|PLAY|
   * `----------------------------------------------------------------'
  */
    [_FL] = LAYOUT_65_iso(
    KC_GRAVE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_BRIGHTNESS_DOWN,KC_SYSTEM_WAKE, \
    _______, _______, BL_INC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_SYSTEM_POWER, \
    _______,  BL_OFF,  BL_DEC,   BL_ON, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_BRIGHTNESS_UP,  KC_SYSTEM_SLEEP, \
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,    KC_AUDIO_VOL_UP,   _______, \
    KC_LCTL, KC_LGUI, KC_LALT,                   _______,                            KC_RALT, _______,    KC_AUDIO_MUTE,KC_AUDIO_VOL_DOWN, KC_MEDIA_PLAY_PAUSE
  )
};

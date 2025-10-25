#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0| ? | ¿ |Backspa |HOM|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     | END|
   * |-------------------------------------------------------|   |----|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ñ|  {| } |Ent|SUPR|
   * |----------------------------------------------------------------|
   * |Shif| <>|  Z|  X|  C|  V|  B|  N|  M| ,;| .:| -_| Shift| Up| FN2|
   * |----------------------------------------------------------------|
   * |Ctrl |Win |Alt |        Space          |Alt | FN|   Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [0] = LAYOUT_65_ansi(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,  KC_ENT,  KC_PGUP, \
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,   KC_UP, KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                               KC_RALT, KC_RCTL, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Keymap _FL1: Function Layer
   * ,----------------------------------------------------------------.
   * | \º| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |WAKE|
   * |----------------------------------------------------------------|
   * |     |   |SC+|   |   |   |   |   |   |   |   |   |   |     | PWD|
   * |----------------------------------------------------------------|
   * |      |   |SC-|   |   |   |   |   |   |   |   |   |   |    |SLEP|
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |    |   |   |     |VL+|    |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |                       |Alt|        |MUT|VL-|PLAY|
   * `----------------------------------------------------------------'
  */
    [1] = LAYOUT_65_ansi(
    KC_GRAVE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,  KC_WAKE, \
    RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R,RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,    _______,   KC_PWR, \
    _______,   RGB_MOD,RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,   _______, KC_SLEP, \
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   KC_VOLU, _______, \
    KC_LCTL, KC_LGUI, KC_LALT,                   RGB_TOG,                                KC_RALT, KC_RCTL, _______, KC_MUTE, KC_VOLD, KC_MPLY
  )
};

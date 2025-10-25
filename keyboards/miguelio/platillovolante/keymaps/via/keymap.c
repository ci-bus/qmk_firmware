#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_3x3(
        RGB_TOG, RGB_MOD, RGB_RMOD,
        KC_F4, KC_F5, KC_F6,
        KC_F7, KC_F8, KC_F9,
              KC_A
    ),
};

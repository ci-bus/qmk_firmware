#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap: (Base Layer) Default Layer
   * ,-------.
   * | 1 | 2 |
   * |-------|
   * | 3 | 4 |
   * `-------'
   */
  [0] = LAYOUT_4_keys(
    KC_1,    KC_2,    
    KC_3,    KC_4
  )
};

// Copyright 2025 Miguelio (teclados@miguelio.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "mv_main.h"
#include "analog.h"
#include "matrix.h"
#include "hardware/gpio.h"
#include "wait.h"
#include "string.h"
#include "print.h"
#include "math.h"
#include "quantum.h"

static uint16_t     matrix_hall_base[MATRIX_ROWS * MATRIX_COLS] = {0};
static pin_t        row_pins[MATRIX_ROWS]                       = MATRIX_ROW_PINS;
static pin_t        col_pins[MATRIX_COLS]                       = MATRIX_COL_PINS;

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void) {
    // TODO: use print() to dump the current matrix state to console
}

void matrix_hall_get_base(void) {
    for (uint8_t t = 0; t < HALL_GET_BASE_ROUNDS; t++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            gpio_write_pin_low(col_pins[col]);
            wait_us(HALL_WAIT_US);
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                matrix_hall_base[(row * MATRIX_COLS) + col] = analogReadPin(row_pins[row]);
            }
            gpio_write_pin_high(col_pins[col]);
        }
    }
}

void get_configurations(void) {
    // Base sensor signal
    matrix_hall_get_base();
}

void matrix_init(void) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        gpio_set_pin_output(col_pins[col]);
        gpio_write_pin_high(col_pins[col]);
    }
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        gpio_set_pin_input(row_pins[row]);
        analogReadPin(row_pins[row]);
    }
    get_configurations();
    wait_ms(3000);
    uprintf("Keyboard inited!\n");
}

bool is_key_position_used(uint8_t layer, uint8_t row, uint8_t col) {
    return keymap_key_to_keycode(layer, (keypos_t){row, col}) != KC_NO;
}

uint8_t matrix_scan(void) {
    return false;
}

// user-defined overridable functions
__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

__attribute__((weak)) void matrix_slave_scan_user(void) {}

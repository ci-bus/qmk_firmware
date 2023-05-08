/*
Copyright 2021 Miguelio <teclados@miguelio.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4D47
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    Miguelio
#define PRODUCT         Miguelio Aquarius
#define DESCRIPTION     Miguelio Aquarius Keyboard

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {D4,F4,B4,D7,F6,B5,B6,F7,F5}
#define MATRIX_COL_PINS {D3,D2,D0,B2,B3,D1,E6,B1}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* The delay when reading the value of the pin */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

#define LED_CAPS_LOCK_PIN B0
#define LED_PIN_ON_STATE 0

/* Backlight configuration */
#define BACKLIGHT_PIN C6
#define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 10

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION


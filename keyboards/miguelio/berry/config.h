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
#define PRODUCT_ID      0x0004
#define DEVICE_VER      0x0001
#define MANUFACTURER    Miguelio
#define PRODUCT         Miguelio Berry
#define DESCRIPTION     Miguelio Berry Proto

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {F5,D1,F4,F1,F0,B6,C6,C7,F6}
#define MATRIX_COL_PINS {B7,F7,D3,D4,D6,D7,B4,B5}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* The delay when reading the value of the pin */
#define DEBOUNCE 5


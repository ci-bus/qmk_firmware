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

#define MATRIX_ROWS 9
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS \
    { D1, F4, B4, B5, F6, F7, F5, B3, B2 }
#define MATRIX_COL_PINS \
    { D3, D2, D4, C6, D7, E6, B1, B6 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

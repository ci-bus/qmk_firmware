// Copyright 2022 ziptyze (@ziptyze)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { GP6, GP12, GP26, GP25, GP22 }
#define MATRIX_COL_PINS { GP18, GP19, GP20, GP21, GP23, GP0, GP5, GP4, GP3, GP2, GP1, GP29, GP28, GP27 }

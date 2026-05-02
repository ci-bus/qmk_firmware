#pragma once

#include <qp.h>

typedef struct {
    uint8_t length;
    uint8_t size;
    bool *data;
} Tetromino;

extern const Tetromino tetrominos[];
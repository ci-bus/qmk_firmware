// Miguelio, open source code

#include "tetrominos.h"

const Tetromino tetrominos[] = {
    // 0 Block
    {4, 2, (bool[]){
        1, 1, 
        1, 1
    }},
    // 1 T
    {9, 3, (bool[]){
        0, 0, 0, 
        1, 1, 1, 
        0, 1, 0
    }},
    // 2 L
    {9, 3, (bool[]){
        0, 1, 0, 
        0, 1, 0, 
        0, 1, 1
    }},
    // 3 J
    {9, 3, (bool[]){
        0, 1, 0, 
        0, 1, 0, 
        1, 1, 0
    }},
    // 4 Straight
    {16, 4, (bool[]){
        0, 0, 0, 0, 
        1, 1, 1, 1, 
        0, 0, 0, 0, 
        0, 0, 0, 0
    }},
    // 5 Z
    {9, 3, (bool[]){
        1, 1, 0, 
        0, 1, 1, 
        0, 0, 0
    }},
    // 6 Zig-zag
    {9, 3, (bool[]){
        0, 1, 1, 
        1, 1, 0, 
        0, 0, 0
    }}
};

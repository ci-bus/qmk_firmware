#include QMK_KEYBOARD_H
#include <qp.h>
#include <wait.h>
#include <quantum.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <qp_draw.h>
#include <qp_internal_formats.h>

#include "gengine.c"

#include "./images/mario.qgf.c"
#include "./elements/parts1.qgf.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_65_all(KC_A, KC_B, KC_C, KC_D), [1] = LAYOUT_65_all(KC_A, KC_B, KC_C, KC_D)};

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128

static painter_device_t display;
static ge_sprite        sprite_mario;
static ge_sprite        sprite_suelo_1;

bool sprite_flipped;

// Control key pressed
static bool pressed_keys[4] = {
    false, // A
    false, // B
    false, // C
    false  // D
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Control pressed keys
    switch (keycode) {
        case KC_A:
            pressed_keys[0] = record->event.pressed;
            if (pressed_keys[0]) {
                ge_flip_sprite(&sprite_mario, pressed_keys[0]);
                ge_set_box(&sprite_mario, 0, 1);
            } else if (!pressed_keys[2]) {
                ge_set_box(&sprite_mario, 0, 0);
            }
            ge_get_element(sprite_mario.element_index)->pos_x--;
            break;
        case KC_B:
            pressed_keys[1] = record->event.pressed;
            break;
        case KC_C:
            pressed_keys[2] = record->event.pressed;
            if (pressed_keys[2]) {
                ge_flip_sprite(&sprite_mario, !pressed_keys[2]);
                ge_set_box(&sprite_mario, 0, 1);
            } else if (!pressed_keys[0]) {
                ge_set_box(&sprite_mario, 0, 0);
            }
            ge_get_element(sprite_mario.element_index)->pos_x++;
            break;
        case KC_D:
            pressed_keys[3] = record->event.pressed;
            break;
    }
    return true;
};

void housekeeping_task_user(void) {
    // Move camera
    int temp_post_x = ge_get_element(sprite_mario.element_index)->pos_x - (IMAGE_WIDTH / 2);
    if (temp_post_x < 0) {
        temp_post_x = 0;
    }
    ge_set_camera_position(temp_post_x, 0);
    // Game engine run
    ge_run(display);
}

void create_map(void) {
    // Create soil
    for (uint16_t pos_x = 0; pos_x < 211; pos_x++) {
        ge_add_sprite_element(&sprite_suelo_1, pos_x * 16, 112);
    }
}

void keyboard_post_init_user(void) {
    // Rand numbers seed
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    // Init screen
    display = qp_st7735_make_spi_device(IMAGE_WIDTH, IMAGE_HEIGHT, TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN, 4, 0);
    qp_init(display, QP_ROTATION_0);
    qp_set_viewport_offsets(display, 2, 1);

    // Init gengine with 10 elements limited
    ge_init_engine(IMAGE_WIDTH, IMAGE_HEIGHT, 512);

    // Clean screen
    ge_clear_screen(display);

    // Create sprite
    sprite_mario   = ge_create_sprite(gfx_mario, gfx_mario_length, 4, 3, 100);
    sprite_suelo_1 = ge_create_sprite(gfx_parts1, gfx_parts1_length, 4, 4, 0);
    ge_set_box(&sprite_suelo_1, 0, 0);
    // Idle sprite state
    // ge_set_box(&sprite_mario, 0, 1);
    // Add sprite to scene
    ge_add_sprite_element(&sprite_mario, 10, 10);
    // active gravity

    // Create map
    create_map();

    // Start game
    ge_start_game();
}

#include QMK_KEYBOARD_H

enum layer_number { _BASE = 0, _LOWER };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */

  [_BASE] = LAYOUT(
    KC_MINS, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
    KC_BSLS, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
    KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_LBRC, KC_RBRC,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC,   KC_GRV, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            KC_LALT, KC_TAB, KC_SCLN, KC_SPC,           KC_ENT, KC_QUOT, KC_BSPC, MO(_LOWER)
  ),
  /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
  [_LOWER] = LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
    KC_CAPS, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______, _______, _______, RGB_TOG,          RGB_MOD, _______, _______, _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [_BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
  [_LOWER] = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  oled_clear();
  return OLED_ROTATION_270; // flips the display 180 degrees if offhand
}

static void render_logo(void) {
  static const char PROGMEM raw_logo[] = {
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,248,252, 60,126,254,255,254,240,128,  0,  0,128,240,254,255,254,126, 60,252,248,240,224,128,  0,  0,  0,  0,  0,  0,255,255,255,255,255,  0,  0,  0,  3,  7, 15, 31, 60, 60, 31, 15,  7,  3,  0,  0,  0,255,255,255,255,255,  0,  0,  0,
      0,240,192,128,131,143,159,191,252,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,252,191,159,143,131,128,192,240,  0,  0,  0,  7,  7,  7,  7,  7,  7,  7,  7,  7,  4,  0,  0,  0,  0,  0,  0,  0,  0,  4,  7,  7,  7,  7,  7,  7,  7,  7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  };
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

#ifdef GAME

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>

  // Live
  int live = 0;
  // Count deaths
  int deaths = 0;
  // Count cycles
  int cycles = 0;
  // Control playing
  bool playing_game_spacecraft = false;
  // Control key pressed
  bool pressed_keys[8] = {
    0, // Start select game
    0, // Number of game
    0, // Left
    0, // Down
    0, // Right
    0, // Up
    0, // Action
    0  // Exit
  };
  // Spacecraft states
  int spacecraft_state[5];
  bool spacecraft_moving = 0;
  bool spacecraft_heading = 0;
  // Bullet states
  int bullet_states[10][3];
  int bullet_state_lag = 0;
  // Enemy states
  int enemy_state[10][5];
  // Ball states
  int ball_state[10][3];
  // Explode states
  int explode_state[20][4];

  // Init states
  void init_states(void) {
    int i;
    live = 32;
    cycles = 0;
    deaths = 0;
    spacecraft_moving = 0;
    spacecraft_heading = 0;
    bullet_state_lag = 0;
    spacecraft_state[0] = 11; // Current X position
    spacecraft_state[1] = 23; // Max X position
    spacecraft_state[2] = 119; // Current Y position
    spacecraft_state[3] = 119; // Max Y position
    spacecraft_state[4] = 0; // Fire sprite index
    for (i = 0; i < 10; i ++) {
      bullet_states[i][0] = 0; // Shoted
      bullet_states[i][1] = 0; // X position
      bullet_states[i][2] = 0; // Y position
      enemy_state[i][0] = 0; // Displaying
      enemy_state[i][1] = 0; // X position
      enemy_state[i][2] = 0; // Y position
      enemy_state[i][3] = 0; // Animation step
      enemy_state[i][4] = 0; // shotted ball
      ball_state[i][0] = 0; // Displaying
      ball_state[i][1] = 0; // X position
      ball_state[i][2] = 0;  // Y position
    }
    for (i = 0; i < 20; i ++) {
      explode_state[i][0] = 0; // Displaying
      explode_state[i][1] = 0; // X position
      explode_state[i][2] = 0; // Y position
      explode_state[i][3] = 0; // Animation step
    }
  }

  // Ball
  static bool ball[9] = {
    0, 1, 0,
    1, 1, 1,
    0, 1, 0
  };
  // sprites
  static bool spacecraft[54] = {
    0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 1, 1, 0, 0, 1
  };
  static bool spacecraft_side[54] = {
    0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 0
  };
  static bool spacecraft_fire[3][9] = {
    {
      0, 1, 0,
      1, 0, 1,
      0, 1, 0
    }, {
      1, 0, 1,
      0, 1, 0,
      0, 0, 0
    }, {
      1, 1, 1,
      1, 1, 1,
      0, 1, 0
    }
  };
  static bool spacecraft_fire_forte[3][12] = {
    {
      1, 0, 1,
      0, 1, 0,
      1, 0, 1,
      0, 1, 0,
    }, {
      0, 1, 0,
      1, 0, 1,
      0, 1, 0,
      1, 0, 1,
    }, {
      1, 1, 1,
      1, 0, 1,
      0, 1, 0,
      0, 0, 0,
    }
  };
  static bool bullet[2] = {
    1,
    1
  };
  static bool enemy[2][25] = {
    {
      0, 1, 1, 1, 0,
      1, 0, 1, 0, 1,
      1, 1, 1, 1, 1,
      1, 1, 1, 1, 1,
      0, 1, 0, 1, 0
    }, {
      0, 1, 1, 1, 0,
      1, 0, 1, 0, 1,
      1, 0, 1, 0, 1,
      1, 1, 1, 1, 1,
      1, 0, 1, 0, 1
    }
  };
  static bool explode_1[25] = {
    0, 1, 0, 1, 0,
    1, 0, 1, 0, 1,
    0, 1, 0, 1, 0,
    1, 0, 1, 0, 1,
    0, 1, 0, 1, 0
  };
  static bool explode_2[49] = {
    0, 1, 1, 0, 1, 1, 0,
    1, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1,
    0, 1, 1, 0, 1, 1, 0
  };
  static bool explode_3[64] = {
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1, 0
  };
  static bool explode_4[64] = {
    0, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 1, 1, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 1, 0
  };
  static bool explode_5[49] = {
    1, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 1
  };
  static bool explode_6[25] = {
    1, 0, 0, 0, 1,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    1, 0, 0, 0, 1
  };

  // Functions
  void draw_sprite(bool* sprite, int x, int y, int cols, int rows){
    for (int iy = 0; iy < rows; iy++) {
      for (int ix = 0; ix < cols; ix++) {
        oled_write_pixel(x + ix, y + iy, sprite[iy * cols + ix]);
      }
    }
  }

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Control pressed keys
    switch (keycode) {
      case KC_G: pressed_keys[0] = record->event.pressed; break;
      case KC_1: pressed_keys[1] = record->event.pressed; break;
      case KC_A: pressed_keys[2] = record->event.pressed; break;
      case KC_S: pressed_keys[3] = record->event.pressed; break;
      case KC_D: pressed_keys[4] = record->event.pressed; break;
      case KC_W: pressed_keys[5] = record->event.pressed; break;
      case KC_SPC: pressed_keys[6] = record->event.pressed; break;
      case KC_ESC: pressed_keys[7] = record->event.pressed; break;
    }
    // Control init game
    if (pressed_keys[0] && pressed_keys[1]) {
      if (live == 0) {
        init_states();
      }
      playing_game_spacecraft = true;
    } else if (pressed_keys[7]) {
      playing_game_spacecraft = false;
    }
    return true;
  };

  // Controls
  void check_key_control(void) {
    spacecraft_moving = 0;
    if (pressed_keys[2]) { //[ A ] move to left
      if (spacecraft_state[0] > 0) spacecraft_state[0] --;
      spacecraft_moving = 1;
    }
    if (pressed_keys[4]) { //[ D ] move to right
      if (spacecraft_state[0] < spacecraft_state[1]) spacecraft_state[0] ++;
      spacecraft_moving = 1;
    }
    if (pressed_keys[5]) { //[ W ] move to up
      if (spacecraft_state[2] > 0) spacecraft_state[2] --;
      spacecraft_heading = 1;
    } else {
      spacecraft_heading = 0;
    }
    if (pressed_keys[3]) { //[ S ] move to down
      if (spacecraft_state[2] < spacecraft_state[3]) spacecraft_state[2] ++;
    }
    if (pressed_keys[6] && !bullet_state_lag) { // fire
      int i;
      for (i = 0; i < 10; i ++) {
        if (!bullet_states[i][0]) {
          bullet_states[i][0] = 1;
          bullet_states[i][1] = spacecraft_state[0] + 1; // Left shot
          bullet_states[i][2] = spacecraft_state[2] + 2;
          if (i % 2) {
            bullet_states[i][1] += 6; // Right shot
          }
          bullet_state_lag = 5;
          break;
        }
      }
    }
  }

  void game_spacecraft_reduce_screen(void) {
    spacecraft_state[3] -= 5;
    spacecraft_state[2] -= 5;
    if (spacecraft_state[2] < 0) {
      spacecraft_state[2] = 0;
    }
    int i;
    for (i = 0; i < 10; i ++) {
      if (bullet_states[i][0]) bullet_states[i][2] -= 7;
      if (enemy_state[i][0]) enemy_state[i][2] -= 7;
      if (ball_state[i][0]) ball_state[i][2] -= 7;
    }
    for (i = 0; i < 20; i ++) {
      if (explode_state[i][0]) explode_state[i][2] -= 7;
    }
  }

  // Engine spacecraft game
  void game_spacecraft_engine(void){
    // Clear display
    oled_clear();
    // Off light
    rgblight_disable();
    if (live > 0 && spacecraft_state[3] > 19) {
      // Temp variables
      int i, j, t, random;
      // Check keys control
      check_key_control();
      // Draw spacecraft
      if (spacecraft_moving) {
        draw_sprite(spacecraft_side, spacecraft_state[0], spacecraft_state[2], 9, 6);
      } else {
        draw_sprite(spacecraft, spacecraft_state[0], spacecraft_state[2], 9, 6);
      }
      // Draw spacecraft fire with low live indicate
      if (live > 12 || cycles % 5 > 2) {
        if (spacecraft_heading) {
          draw_sprite(spacecraft_fire_forte[spacecraft_state[4]], spacecraft_state[0] + 3, spacecraft_state[2] + 6, 3, 4);
        } else {
          draw_sprite(spacecraft_fire[spacecraft_state[4]], spacecraft_state[0] + 3, spacecraft_state[2] + 6, 3, 3);
        }
      }
      // Update fire state
      spacecraft_state[4] ++;
      if (spacecraft_state[4] > 2) spacecraft_state[4] = 0;
      // Bullet
      for (i = 0; i < 10; i ++) {
        if (bullet_states[i][0]) {
          // Move
          bullet_states[i][2] -= 2;
          if (bullet_states[i][2] < 0) {
            bullet_states[i][0] = 0;
          } else {
            // Check shot impact
            for (j = 0; j < 10; j ++) {
              if (enemy_state[j][0]
                && bullet_states[i][1] >= enemy_state[j][1] && bullet_states[i][1] <= enemy_state[j][1] + 5
                && bullet_states[i][2] >= enemy_state[j][2] && bullet_states[i][2] <= enemy_state[j][2] + 5) {
                // Remove bullet and enemy
                bullet_states[i][0] = 0;
                enemy_state[j][0] = 0;
                // Add explode
                for (t = 0; t < 15; t ++) {
                  if (!explode_state[t][0]) {
                    explode_state[t][0] = 1;
                    explode_state[t][1] = enemy_state[j][1];
                    explode_state[t][2] = enemy_state[j][2];
                    explode_state[t][3] = 0;
                    break;
                  }
                }
                // Increase deaths
                deaths ++;
              }
            }
            // Draw bullet
            if (bullet_states[i][0]) {
              draw_sprite(bullet, bullet_states[i][1], bullet_states[i][2], 1, 2);
            }
          }
        }
      }
      // Reduce shotting lag
      if (bullet_state_lag) {
        bullet_state_lag --;
      }

      // Generate Enemies
      int interval = 60 - deaths;
      if (interval < 10) interval = 10;
      if (cycles > interval) {
        for (i = 0; i < 10; i ++) {
          if (!enemy_state[i][0]) {
            enemy_state[i][0] = 1;
            enemy_state[i][1] = rand() % 27;
            enemy_state[i][2] = -5;
            enemy_state[i][4] = 0;
            break;
          }
        }
        cycles = 0;
      }
      // Draw Enemies
      for (i = 0; i < 10; i ++) {
        if (enemy_state[i][0]) {
          draw_sprite(enemy[enemy_state[i][3]], enemy_state[i][1], enemy_state[i][2], 5, 5);
          // Random value
          random = rand() % 50;
          // Move enemy
          if (random < 35) {
            enemy_state[i][2] += 2;
          } else if (random < 40) {
            enemy_state[i][1] += 2;
            if (enemy_state[i][1] > 27) enemy_state[i][1] = 27;
          } else if (random < 45) {
            enemy_state[i][1] -= 2;
            if (enemy_state[i][1] < 0) enemy_state[i][1] = 0;
          }
          // Shot ball
          if (enemy_state[i][4] == 0 && deaths > 10 && random > 47) {
            enemy_state[i][4] = 1;
            for (j = 0; j < 10; j ++) {
              if (ball_state[j][0] == 0) {
                ball_state[j][0] = 1;
                ball_state[j][1] = enemy_state[i][1] + 1;
                ball_state[j][2] = enemy_state[i][2] + 5;
                break;
              }
            }
          }
          // Check impact
          if (enemy_state[i][1] > spacecraft_state[0] - 5 && enemy_state[i][1] < spacecraft_state[0] + 9
            && enemy_state[i][2] > spacecraft_state[2] - 5 && enemy_state[i][2] < spacecraft_state[2] + 6) {
            // Reduce live
            live -= 2;
            // On light
            rgblight_enable();
            // Remove ball
            enemy_state[i][0] = 0;
            // Add explode
            for (t = 0; t < 15; t ++) {
              if (!explode_state[t][0]) {
                explode_state[t][0] = 1;
                explode_state[t][1] = enemy_state[i][1];
                explode_state[t][2] = enemy_state[i][2];
                explode_state[t][3] = 0;
                break;
              }
            }
            // Draw all white screen
            for (j = 0; j < 128; j ++) {
              for (t = 0; t < 32; t ++) {
                oled_write_pixel(t, j, 1);
              }
            }
          }
          // Increase animation step
          enemy_state[i][3] ++;
          if (enemy_state[i][3] > 1) enemy_state[i][3] = 0;
          // Remove enemy out of screen
          if (enemy_state[i][2] > spacecraft_state[3] + 9) {
            enemy_state[i][0] = 0;
            // Reduce screen size
            game_spacecraft_reduce_screen();
          }
        }
      }

      // Balls
      for (i = 0; i < 10; i ++) {
        if (ball_state[i][0]) {
          // Draw balls
          draw_sprite(ball, ball_state[i][1], ball_state[i][2], 3, 3);
          // Check impact
          if (ball_state[i][1] > spacecraft_state[0] - 3 && ball_state[i][1] < spacecraft_state[0] + 9
            && ball_state[i][2] > spacecraft_state[2] - 3 && ball_state[i][2] < spacecraft_state[2] + 6) {
            // Reduce live
            live -= 2;
            // On light
            rgblight_enable();
            // Remove ball
            ball_state[i][0] = 0;
            // Add explode
            for (t = 0; t < 15; t ++) {
              if (!explode_state[t][0]) {
                explode_state[t][0] = 1;
                explode_state[t][1] = ball_state[i][1] - 1;
                explode_state[t][2] = ball_state[i][2] - 1;
                explode_state[t][3] = 0;
                break;
              }
            }
            // Draw all white screen
            for (j = 0; j < 128; j ++) {
              for (t = 0; t < 32; t ++) {
                oled_write_pixel(t, j, 1);
              }
            }
          }
          // Move balls
          ball_state[i][2] += 2;
          // Remove ball out of screen
          if (ball_state[i][2] > spacecraft_state[3] + 9) {
            ball_state[i][0] = 0;
          }
        }
      }

      // Draw explosions
      for (i = 0; i < 10; i ++) {
        if (explode_state[i][0]) {
          // Step animation
          switch (explode_state[i][3]) {
            case 0: draw_sprite(explode_1, explode_state[i][1], explode_state[i][2], 5, 5); break;
            case 1: draw_sprite(explode_2, explode_state[i][1] - 1, explode_state[i][2] - 1, 7, 7); break;
            case 2: draw_sprite(explode_3, explode_state[i][1] - 2, explode_state[i][2] - 2, 8, 8); break;
            case 3: draw_sprite(explode_4, explode_state[i][1] - 2, explode_state[i][2] - 2, 8, 8); break;
            case 4: draw_sprite(explode_5, explode_state[i][1] - 1, explode_state[i][2] - 1, 7, 7); break;
            case 5: draw_sprite(explode_6, explode_state[i][1], explode_state[i][2], 5, 5); break;
          }
          // Finally animation
          explode_state[i][3] ++;
          if (explode_state[i][3] > 5) {
            explode_state[i][0] = 0;
          }
        }
      }

      // Draw live
      for (i = 0; i < live; i ++) {
        oled_write_pixel(i, 0, 1);
      }

      // Draw limit screen 119
      for (j = 0; j < 32; j ++) {
        int onda = ((j + cycles) % 3);
        oled_write_pixel(j, spacecraft_state[3] + 9 + onda, 1);
      }

      // Increase cycles
      cycles ++;
    } else {
      // Draw gameover
      oled_set_cursor(0, 4);
      oled_write_ln("GAME", false);
      oled_write_ln("OVER", false);
      oled_write_ln(" ", false);
      char counter[10];
      sprintf(counter, "%d", deaths);
      oled_write_ln(counter, false);
    }
  }
#endif

bool oled_task_user(void) {
  if (is_keyboard_master()) {
#ifdef GAME
    if (playing_game_spacecraft) game_spacecraft_engine();
    else render_logo();
#else
    render_logo();
#endif
  } else {
    render_logo();
  }
  return false;
}

#endif // OLED_ENABLE

#include <qp.h>
#include <qp_internal_formats.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    uint8_t        boxs_x;
    uint8_t        boxs_y;
    uint8_t        current_box_x;
    uint8_t        current_box_y;
    uint8_t        image_head_size;
    uint32_t       last_time;
    uint16_t       interval;
    int8_t         element_index;
    const uint8_t *image;
} ge_sprite;

typedef struct {
    ge_sprite *sprite;
    int16_t    pos_x;
    int16_t    pos_y;
    uint8_t    gravity;
    bool       flipped;
    bool       used;
} ge_element;

typedef struct {
    int16_t pos_x;
    int16_t pos_y;
} ge_camera;

#define GE_IMAGE_HEAD_SIZE 48
#define GE_MILLIS_FRAME 33

static uint16_t    gengine_width             = 0;
static uint16_t    gengine_height            = 0;
static uint16_t   *gengine_buffer            = NULL;
static ge_element *gengine_elements          = NULL;
static uint8_t     gengine_elements_count    = 0;
static uint16_t    gengine_empty_pixel_color = 0xFFFF;
static float       gengine_delta             = 0;
static uint32_t    gengine_last_draw         = 0;
static bool        gengine_started           = false;
static ge_camera   gengine_camera;

uint16_t *ge_init_engine(uint16_t width, uint16_t height, uint8_t elements_count) {
    gengine_width          = width;
    gengine_height         = height;
    gengine_elements_count = elements_count;
    gengine_camera.pos_x   = 0;
    gengine_camera.pos_y   = 0;
    gengine_buffer         = (uint16_t *)malloc(width * height * sizeof(uint16_t));
    gengine_elements       = (ge_element *)malloc(gengine_elements_count * sizeof(ge_element));
    for (uint8_t i = 0; i < gengine_elements_count; i++) {
        gengine_elements[i].used = false;
    }
    return gengine_buffer;
}

void ge_move_camera(int16_t x, int16_t y) {
    gengine_camera.pos_x += x;
    gengine_camera.pos_y += y;
}

void ge_set_pixel(struct painter_driver_t *driver, uint16_t x, uint16_t y, uint16_t rgb565) {
    qp_pixel_t    color;
    unsigned char r        = (rgb565 >> 11) & 0x1F;
    unsigned char g        = (rgb565 >> 5) & 0x3F;
    unsigned char b        = rgb565 & 0x1F;
    unsigned char r_scaled = (r * 255) / 31;
    unsigned char g_scaled = (g * 255) / 63;
    unsigned char b_scaled = (b * 255) / 31;
    unsigned char max_val  = (r_scaled > g_scaled) ? r_scaled : g_scaled;
    max_val                = (max_val > b_scaled) ? max_val : b_scaled;
    unsigned char min_val  = (r_scaled < g_scaled) ? r_scaled : g_scaled;
    min_val                = (min_val < b_scaled) ? min_val : b_scaled;
    color.hsv888.v         = max_val;
    if (max_val == 0) {
        color.hsv888.s = 0;
        color.hsv888.h = 0;
    } else {
        color.hsv888.s = 255 * (max_val - min_val) / max_val;
        if (max_val == r_scaled) {
            color.hsv888.h = 0 + 43 * (g_scaled - b_scaled) / (max_val - min_val);
        } else if (max_val == g_scaled) {
            color.hsv888.h = 85 + 43 * (b_scaled - r_scaled) / (max_val - min_val);
        } else {
            color.hsv888.h = 171 + 43 * (r_scaled - g_scaled) / (max_val - min_val);
        }
    }
    driver->driver_vtable->palette_convert(driver, 1, &color);
    gengine_buffer[y * gengine_width + x] = color.rgb565;
}

void ge_draw(painter_device_t display) {
    qp_pixdata(display, gengine_buffer, gengine_width * gengine_height);
    qp_flush(display);
}

void ge_clear_buffer(uint16_t color) {
    for (uint16_t i = 0; i < gengine_width * gengine_height; i++) {
        gengine_buffer[i] = color;
    }
}

void ge_clear_screen(painter_device_t display) {
    ge_clear_buffer(0x0000);
    qp_rect(display, 0, 0, gengine_width - 1, gengine_height - 1, 0, 0, 0, true);
    qp_flush(display);
}

void ge_change_empty_pixel_color(uint16_t color) {
    gengine_empty_pixel_color = color;
}

ge_sprite ge_create_sprite(const uint8_t *image, uint32_t length, uint8_t boxs_x, uint8_t boxs_y, uint16_t interval) {
    ge_sprite sprite;
    sprite.boxs_x          = boxs_x;
    sprite.boxs_y          = boxs_y;
    sprite.current_box_x   = 0;
    sprite.current_box_y   = 0;
    sprite.image_head_size = GE_IMAGE_HEAD_SIZE;
    sprite.interval        = interval;
    sprite.last_time       = 0;
    sprite.image           = image;
    sprite.element_index   = -1;
    return sprite;
}

void ge_set_box(ge_sprite *sprite, uint8_t box_x, uint8_t box_y) {
    sprite->current_box_x = box_x % sprite->boxs_x;
    sprite->current_box_y = box_y % sprite->boxs_y;
}

void ge_next_sprite(ge_sprite *sprite) {
    ge_set_box(sprite, sprite->current_box_x + 1, sprite->current_box_y);
}

void ge_flip_sprite(ge_sprite *sprite, bool flipped) {
    int8_t i = sprite->element_index;
    if (i != -1) {
        gengine_elements[i].flipped = flipped;
    }
}

bool ge_add_sprite_element(ge_sprite *sprite, int16_t x, int16_t y) {
    // Find free element index
    for (uint8_t i = 0; i < gengine_elements_count; i++) {
        if (!gengine_elements[i].used) {
            gengine_elements[i].used    = true;
            gengine_elements[i].sprite  = sprite;
            gengine_elements[i].pos_x   = x;
            gengine_elements[i].pos_y   = y;
            gengine_elements[i].flipped = false;
            sprite->element_index       = i;
            return true;
        }
    }
    return false;
}

void ge_put_sprite(struct painter_driver_t *driver, ge_element *element) {
    // Image width from head
    uint16_t image_width = element->sprite->image[18];
    image_width          = (image_width << 8) | element->sprite->image[17];
    // Image height from head
    uint16_t image_height = element->sprite->image[20];
    image_height          = (image_height << 8) | element->sprite->image[19];
    // Boxs sizes
    uint16_t box_width  = image_width / element->sprite->boxs_x;
    uint16_t box_height = image_height / element->sprite->boxs_y;
    // Position according to camera
    int16_t pos_y = element->pos_y - gengine_camera.pos_y;
    int16_t pos_x = element->pos_x - gengine_camera.pos_x;
    // Calcule element pixels frame to draw
    uint16_t sy = pos_y < 0 ? abs(pos_y) : 0;
    uint16_t sx = pos_x < 0 ? abs(pos_x) : 0;
    int16_t  fy = pos_y + box_height > gengine_height ? box_height - (pos_y + box_height - gengine_height) : box_height;
    int16_t  fx = pos_x + box_width > gengine_width ? box_width - (pos_x + box_width - gengine_width) : box_width;

    for (int16_t iy = sy; iy < fy; iy++) {
        for (int16_t ix = sx; ix < fx; ix++) {
            uint16_t iflipx = element->flipped ? box_width - ix : ix;
            //  Calcule sprite hex color index
            uint16_t i = (((element->sprite->current_box_y * box_height + iy) * image_width + iflipx) * 2) + element->sprite->image_head_size;
            i += element->sprite->current_box_x * (box_width * 2);
            // Pixel rgb565, 8 + 8 bits
            uint16_t pixel = ((uint16_t)element->sprite->image[i] << 8);
            pixel |= (uint16_t)element->sprite->image[i + 1];
            // If it isn't "transparent"
            if (pixel != gengine_empty_pixel_color) {
                ge_set_pixel(driver, pos_x + ix, pos_y + iy, pixel);
            }
        }
    }
    if (element->sprite->interval && timer_elapsed32(element->sprite->last_time) > element->sprite->interval) {
        element->sprite->last_time = timer_read32();
        ge_next_sprite(element->sprite);
    }
}

void ge_put_sprites(painter_device_t display) {
    struct painter_driver_t *driver = (struct painter_driver_t *)display;
    for (uint8_t i = 0; i < gengine_elements_count; i++) {
        if (gengine_elements[i].used) {
            ge_put_sprite(driver, &gengine_elements[i]);
        }
    }
}

void ge_run(painter_device_t display) {
    if (gengine_started && timer_elapsed32(gengine_last_draw) > GE_MILLIS_FRAME) { // Throttle to 30fps
        gengine_delta     = timer_elapsed32(gengine_last_draw) / GE_MILLIS_FRAME;
        gengine_last_draw = timer_read32();
        // Clear buffer
        ge_clear_buffer(0xFFFF);
        // Put sprites
        ge_put_sprites(display);
        // Draw screen
        ge_draw(display);
    }
}

void ge_start_game(void) {
    gengine_last_draw = timer_read32();
    gengine_started   = true;
}
#pragma once

#define PICO_FLASH_SIZE_BYTES (512 * 1024)

// Display Configuration
#define SPI_SCK_PIN GP19
#define SPI_MOSI_PIN GP18
#define SPI_MISO_PIN GP17

#define TFT_CS_PIN GP12
#define TFT_DC_PIN GP11
#define TFT_RST_PIN GP10

#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE

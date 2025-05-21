// User_Setup.h - Setup per display TFT SPI 3.5"/5" + STM32 Blue Pill

#define ILI9486_DRIVER   // oppure ILI9488_DRIVER se hai quel controller

#define TFT_WIDTH  480
#define TFT_HEIGHT 320

// Pin STM32 Blue Pill
#define TFT_MOSI PA7
#define TFT_SCLK PA5
#define TFT_CS   PA4
#define TFT_DC   PA3
#define TFT_RST  PA2  // puoi anche commentare se non connesso

// Carica font
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY  27000000

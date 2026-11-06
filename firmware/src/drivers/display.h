#include <Adafruit_ST7735.h>

void display_init();

Adafruit_ST7735& display_get();

void display_clear();

void display_flush();

void display_show_text(int x, int y, int size, char color, char text);

void display_load_image(uint16_t x, uint16_t y, const uint16_t *img_matrix, uint16_t w, uint16_t h);

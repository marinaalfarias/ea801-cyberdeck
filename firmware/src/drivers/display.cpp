#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include "drivers/display.h"
#include "pins.h"

#define TFT_CS   10
#define TFT_RST   9
#define TFT_DC    8
#define TFT_MOSI 11
#define TFT_SCLK 12

static Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void display_init() {
    delay(150);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    tft.initR(INITR_BLACKTAB);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);
}

Adafruit_ST7735& display_get() { return tft; }

void display_clear() {
    tft.fillScreen(ST77XX_BLACK);
}

void display_flush() {}

void display_show_text(int x, int y, int size, char color, char text) {
    tft.setCursor(x, y);
    tft.setTextSize(size);
    tft.setTextColor(color);
    tft.println(text);
    return;
}

void display_load_image(uint16_t x, uint16_t y, const uint16_t *img_matrix, uint16_t w, uint16_t h) {
    tft.drawRGBBitmap(x, y, img_matrix, w, h);
    return;
}
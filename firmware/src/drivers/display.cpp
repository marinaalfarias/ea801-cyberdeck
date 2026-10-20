#include "display.h"
#include "pins.h"
#include <Adafruit_GFX.h>
#include <SPI.h>

static Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void display_init() {
    delay(150);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    tft.initR(INITR_BLACKTAB);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_GREEN);
    tft.setTextColor(ST77XX_MAGENTA);
}

Adafruit_ST7735& display_get() { return tft; }

void display_clear() {
    tft.fillScreen(ST77XX_BLACK);
}

void display_flush() {}
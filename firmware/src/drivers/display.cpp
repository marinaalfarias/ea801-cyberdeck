#include "display.h"
#include "pins.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Instancia o objeto global do TFT
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display_init() {
    tft.initR(INITR_GREENTAB); // Se a cor ficar estranha, tente BLACKTAB
    tft.setRotation(1);        // Ajusta a orientação
    tft.fillScreen(ST77XX_BLACK);
}

Adafruit_ST7735& display_get() { return tft; }
void display_clear() { tft.fillScreen(ST77XX_BLACK); }
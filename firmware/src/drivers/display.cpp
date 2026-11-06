#include "display.h"
#include "pins.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Objeto global do TFT
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display_init() {
    Serial.println("[Display] Iniciando...");

    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS); // SCLK, MISO, MOSI, SS
    SPI.setFrequency(40000000); // 40 MHz
    
    #ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    #endif

    // Tente INITR_GREENTAB ou INITR_BLACKTAB
    tft.initR(INITR_GREENTAB); 
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);
    
    Serial.println("[Display] OK.");
}

Adafruit_ST7735& display_get() {
    return tft;
}

void display_clear() {
    tft.fillScreen(ST77XX_BLACK);
}
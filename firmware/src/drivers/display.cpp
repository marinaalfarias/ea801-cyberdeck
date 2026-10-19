#include "display.h"
#include "pins.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Criar objeto TFT
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display_init() {
    // Se o pino BL existir, ligar o backlight
    #ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    #endif

    // Inicializar (o modelo pode precisar ser ajustado)
    tft.initR(INITR_BLACKTAB);  // Se as cores estiverem erradas, tente INITR_GREENTAB ou INITR_REDTAB
    
    tft.setRotation(1);  // Ajustar orientação (0-3)
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setCursor(0, 0);
}

Adafruit_ST7735& display_get() {
    return tft;
}

void display_clear() {
    tft.fillScreen(ST77XX_BLACK);
}
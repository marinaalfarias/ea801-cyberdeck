#include "screen_game.h"
#include "sprites.h"
#include "drivers/display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

void screen_game_draw(EstadoCriatura estado) {
    Adafruit_ST7735& tft = display_get();
    tft.fillScreen(ST77XX_BLACK);

    // Desenha a imagem (ajuste as dimensões se você redimensionou)
    // tft.drawRGBBitmap(0, 0, fofinho_fofinho, 128, 121);

    // Desenha o texto do estado por cima
    tft.setCursor(10, 10);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);
    
    switch(estado) {
        case OVO: tft.print("OVO"); break;
        case BEBE: tft.print("BEBE"); break;
        case ADULTO: tft.print("ADULTO"); break;
        case DORMINDO: tft.print("DORMINDO"); break;
        case MORTO: tft.print("MORTO"); break;
    }
}
#include "screen_game.h"
#include "upper_frame.h" 
#include "services/game_engine.h"
#include "drivers/display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

void draw_upper_frame(EstadoCriatura estado) {
    Adafruit_ST7735& tft = display_get();
    
    switch (estado) {
        case OVO:
            tft.drawRGBBitmap(0, 0, ovo, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case CHOCANDO:
            tft.drawRGBBitmap(0, 0, ovo_chocando, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case NORMAL:        
            tft.drawRGBBitmap(0, 0, normal, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case TRISTE:
            tft.drawRGBBitmap(0, 0, triste, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case DORMINDO:
            tft.drawRGBBitmap(0, 0, dormindo, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case FELIZ:
            tft.drawRGBBitmap(0, 0, super_feliz, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case BRAVO:
            tft.drawRGBBitmap(0, 0, bravo, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        case MORTO:
            tft.drawRGBBitmap(0, 0, morto, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT);
            break;
        default:
            tft.fillRect(0, 0, UPPER_FRAME_WIDTH, UPPER_FRAME_HEIGHT, ST77XX_RED); // Cor de erro
            break;
    }
}

void screen_game_draw(EstadoCriatura estado) {
    Adafruit_ST7735& tft = display_get();
    StatusCriatura st = game_engine_status();
    
    // 1. Limpa APENAS a área do texto (parte de baixo)
    tft.fillRect(0, 80, 128, 80, 0x958F); // fundo verde-sálvia
    
    // 2. Desenha a imagem do bichinho na parte de cima
    draw_upper_frame(estado);
    
    // 3. Desenha os textos dos status
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(1);
    
    // Fome
    tft.setCursor(5, 90);
    tft.print("Fome: ");
    tft.print(st.fome);
    tft.print("/100");
    
    // Felicidade
    tft.setCursor(5, 105);
    tft.print("Energia: ");
    tft.print(st.energia);
    tft.print("/100");
}

// Desenha APENAS a imagem de cima (lento, mas só quando o estado muda)
void screen_game_draw_image(EstadoCriatura estado) {
    Adafruit_ST7735& tft = display_get();
    tft.fillScreen(0x958F);      // Limpa tudo
    draw_upper_frame(estado);    // Desenha a imagem
}

// Desenha APENAS os textos de baixo (rápido, quando os valores mudam)
void screen_status_draw() {
    Adafruit_ST7735& tft = display_get();
    StatusCriatura st = game_engine_status();
    
    tft.fillRect(0, 80, 128, 80, 0x958F); // Limpa só a área do texto
    
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(1);
    
    tft.setCursor(5, 90);
    tft.print("Fome: "); tft.print(st.fome); tft.print("/100");
    
    tft.setCursor(5, 105);
    tft.print("Energia: "); tft.print(st.energia); tft.print("/100");
}
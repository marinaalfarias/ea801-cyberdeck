#include <Arduino.h>
#include "config.h"
#include "services/game_engine.h"
#include "ui/screen_game.h"
#include "drivers/buzzer.h"

void taskUI(void *pv) {
    TickType_t last = xTaskGetTickCount();
    EstadoCriatura estado_anterior = MORTO;
    int energia_anterior = -1;
    int fome_anterior = -1;
    int felicidade_anterior = -1;

    for (;;) {
        StatusCriatura st = game_engine_status();
        
        bool estado_mudou = (st.estado != estado_anterior);
        bool status_mudou = (abs(st.fome - fome_anterior) >= 2) ||
                            (abs(st.energia - energia_anterior) >= 2) ||
                            (abs(st.felicidade - felicidade_anterior) >= 2);
        
        if (estado_mudou) {
            // Estado mudou: redesenha a imagem E o texto
            Serial.print("[UI] Estado mudou para: ");
            Serial.println(st.estado);
            screen_game_draw_image(st.estado);
            screen_status_draw();
            
            estado_anterior = st.estado;
            energia_anterior = st.energia;
            fome_anterior = st.fome;
            felicidade_anterior = st.felicidade;

            switch (st.estado) {
                case OVO: som_ovo(); break;
                case CHOCANDO: som_chocando(); break;
                case TRISTE: som_triste(); break;
                case BRAVO: som_bravo(); break;
                case DORMINDO: som_dormindo(); break;
                case MORTO: som_morto(); break;
                case FELIZ: som_feliz(); break;
                default: break; // Não toca som para NORMAL ou MENU
            }
        }
        else if (status_mudou) {
            // Só os valores mudaram: redesenha APENAS o texto (rápido)
            screen_status_draw();
            
            energia_anterior = st.energia;
            fome_anterior = st.fome;
            felicidade_anterior = st.felicidade;
        }
        
        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_UI_MS));
    }
}
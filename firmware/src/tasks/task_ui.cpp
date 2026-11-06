#include <Arduino.h>
#include "config.h"
#include "services/game_engine.h"
#include "ui/screen_game.h"

void taskUI(void *pv) {
    TickType_t last = xTaskGetTickCount();
    EstadoCriatura estado_anterior = MORTO;
    int energia_anterior = -1;
    int fome_anterior = -1;
    int felicidade_anterior = -1;

    for (;;) {
        StatusCriatura st = game_engine_status();
        
        // Declara as variáveis ANTES de usar
        bool estado_mudou = (st.estado != estado_anterior);
        bool energia_caiu = (abs(st.energia - energia_anterior) >= 10);
        bool fome_caiu = (abs(st.fome - fome_anterior) >= 10);
        bool felicidade_caiu = (abs(st.felicidade - felicidade_anterior) >= 10);
        
        // Usa as variáveis na condição
        if (estado_mudou || energia_caiu || fome_caiu || felicidade_caiu) {
            screen_game_draw(st.estado);
            estado_anterior = st.estado;
            energia_anterior = st.energia;
            fome_anterior = st.fome;
            felicidade_anterior = st.felicidade;
            tela_precisa_atualizar = false;
        }
        
        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_UI_MS));
    }
}
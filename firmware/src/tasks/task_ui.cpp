#include <Arduino.h>
#include "config.h"
#include "services/game_engine.h"
#include "drivers/display.h" // Se o display não estiver pronto, comente essa linha

void taskUI(void *pv) {
    TickType_t last = xTaskGetTickCount();
    
    for (;;) {
        StatusCriatura st = game_engine_status();
        
        // --- DEBUG NO MONITOR SERIAL ---
        Serial.print("Estado: ");
        switch(st.estado) {
            case OVO: Serial.print("OVO"); break;
            case BEBE: Serial.print("BEBE"); break;
            case ADULTO: Serial.print("ADULTO"); break;
            case MORTO: Serial.print("MORTO"); break;
            default: Serial.print("DESCONHECIDO"); break;
        }
        Serial.print(" | Fome: "); Serial.print(st.fome);
        Serial.print(" | Felicidade: "); Serial.print(st.felicidade);
        Serial.print(" | Energia: "); Serial.print(st.energia);
        Serial.print(" | Idade: "); Serial.print(st.idade_s);
        Serial.println("s");
        // --------------------------------

        // Futuramente aqui entrará o desenho no TFT:
        // screen_game_draw();

        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_UI_MS));
    }
}
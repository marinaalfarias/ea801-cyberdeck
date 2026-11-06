#include <Arduino.h>
#include "drivers/ldr.h"
#include "services/game_engine.h"

void taskSensores(void *pv) {
    for (;;) {
        // Se estiver escuro, o bichinho dorme
        if (ldr_is_dark()) {
            game_engine_status().estado = DORMINDO; 
        }
        vTaskDelay(pdMS_TO_TICKS(500)); // Lê o LDR a cada meio segundo
    }
}
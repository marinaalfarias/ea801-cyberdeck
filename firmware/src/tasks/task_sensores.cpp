#include <Arduino.h>
#include "drivers/ldr.h"
#include "services/game_engine.h"

void taskSensores(void *pv) {
    for (;;) {
        bool escuro = ldr_is_dark();        // Lê o LDR
        game_engine_set_luz(escuro);        // Avisa o game_engine
        vTaskDelay(pdMS_TO_TICKS(500));     // Lê a cada 500 ms
    }
}
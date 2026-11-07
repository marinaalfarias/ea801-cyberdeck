#include <Arduino.h>
#include "services/game_engine.h"

void taskJogo(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        game_engine_tick(); // Faz a fome aumentar, envelhecer, etc.
        vTaskDelayUntil(&last, pdMS_TO_TICKS(1000)); // 1 segundo
    }
}
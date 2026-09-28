#include <Arduino.h>
#include "config.h"
#include "services/game_engine.h"

void taskJogo(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        game_engine_tick();
        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_JOGO_MS));
    }
}
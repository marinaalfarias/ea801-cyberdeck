#include <Arduino.h>
#include "config.h"

void taskUI(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        // Aqui vai a atualização da tela (display)
        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_UI_MS));
    }
}
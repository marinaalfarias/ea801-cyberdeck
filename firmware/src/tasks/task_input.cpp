#include <Arduino.h>
#include "config.h"

void taskInput(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        // Aqui vai a leitura dos botões
        vTaskDelayUntil(&last, pdMS_TO_TICKS(20));
    }
}
#include <Arduino.h>
#include "config.h"

void taskSensores(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        // Aqui vai a leitura do MPU6050 e do LDR
        vTaskDelayUntil(&last, pdMS_TO_TICKS(TICK_SENSORES_MS));
    }
}
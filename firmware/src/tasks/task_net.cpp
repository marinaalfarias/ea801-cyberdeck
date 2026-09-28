#include <Arduino.h>
#include "config.h"

void taskNet(void *pv) {
    TickType_t last = xTaskGetTickCount();
    for (;;) {
        // Aqui vai a reconexão Wi-Fi e NTP
        vTaskDelayUntil(&last, pdMS_TO_TICKS(1000));
    }
}
#include <Arduino.h>
#include "drivers/ldr.h"
#include "services/game_engine.h"

void taskSensores(void *pv) {
    for (;;) {
        int valor_luz = ldr_get_value();
        Serial.print("Luz lida: ");
        Serial.println(valor_luz); // Veja os valores aqui!

        if (ldr_is_dark()) {
            game_engine_status().estado = DORMINDO; 
            Serial.println("Dormindo...");
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
}
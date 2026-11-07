#include <Arduino.h>
#include "drivers/ldr.h"
#include "services/game_engine.h"

void taskSensores(void *pv) {
    for (;;) {
        // Lê o valor bruto do LDR (0 a 4095)
        int valor_ldr = ldr_get_value();
        
        // Verifica se está escuro (ajuste o limiar conforme necessário)
        bool escuro = ldr_is_dark();
        
        // Imprime no Monitor Serial
        Serial.print("[LDR] Valor: ");
        Serial.print(valor_ldr);
        Serial.print(" | Escuro? ");
        Serial.println(escuro ? "SIM" : "NAO");
        
        // Avisa o game_engine para mudar o estado (dormir/acordar)
        game_engine_set_luz(escuro);
        
        vTaskDelay(pdMS_TO_TICKS(500)); // Lê a cada 500 ms
    }
}
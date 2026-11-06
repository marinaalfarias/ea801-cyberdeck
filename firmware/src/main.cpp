#include <Arduino.h>
#include "pins.h"
#include "config.h"

// --- Includes de Drivers (hardware) ---
#include "drivers/display.h"
#include "drivers/imu.h"
#include "drivers/buttons.h"
#include "drivers/ldr.h"
#include "drivers/buzzer.h"

// --- Includes de Serviços (lógica) ---
#include "services/game_engine.h"
#include "services/wifi_manager.h"
#include "services/power_manager.h"

// --- Protótipos das Tasks (definidas em src/tasks/) ---
void taskUI(void *pv);
void taskInput(void *pv);
void taskSensores(void *pv);
void taskJogo(void *pv);
void taskNet(void *pv);

void setup() {
    // 1. Comunicação Serial para debug
    Serial.begin(115200);
    delay(500); // Dá um tempinho para o monitor serial conectar
    Serial.println("\n--- Iniciando CyberDeck-Tama ---");

    // 2. Inicialização de todos os periféricos (Hardware)
    Serial.println("Inicializando perifericos...");
    display_init();
    imu_init();
    buttons_init();
    ldr_init();
    buzzer_init();
    
    // 3. Inicialização dos serviços (Lógica)
    game_engine_init();
    
    Serial.println("Perifericos e servicos prontos.");

    // 4. Criação das Tasks do FreeRTOS
    Serial.println("Criando tasks...");
    
    // Núcleo 1: Focado na interface e entradas do usuário
    xTaskCreatePinnedToCore(taskUI,       "UI",       4096, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskInput,    "Input",    2048, nullptr, 2, nullptr, 1);
    
    // Núcleo 0: Focado na lógica pesada, sensores e rede
    xTaskCreatePinnedToCore(taskSensores, "Sensores", 3072, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskJogo,     "Jogo",     4096, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskNet,      "Net",      4096, nullptr, 0, nullptr, 0);

    Serial.println("Tasks criadas! Sistema rodando.");
}

void loop() {
    // O loop principal fica vazio (ou com sleep longo).
    // Toda a mágica acontece dentro das tasks criadas acima.
    vTaskDelay(pdMS_TO_TICKS(10000)); 
}
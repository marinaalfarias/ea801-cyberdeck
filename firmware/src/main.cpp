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
    Serial.begin(115200);
    delay(500);
    Serial.println("\n--- Iniciando Tamagochi ---");

    // Inicialização de todos os periféricos
    display_init();
    imu_init();
    buttons_init();
    ldr_init();
    buzzer_init();
    
    // Inicialização dos serviços
    game_engine_init();

    // Criação das Tasks (descomente estas linhas)
    xTaskCreatePinnedToCore(taskUI,       "UI",       4096, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskInput,    "Input",    2048, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskSensores, "Sensores", 3072, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskJogo,     "Jogo",     4096, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskNet,      "Net",      4096, nullptr, 0, nullptr, 0);

    Serial.println("Tasks criadas! Sistema rodando.");
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(10000));
}
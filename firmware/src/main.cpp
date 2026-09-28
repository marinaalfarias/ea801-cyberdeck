#include <Arduino.h>
#include "pins.h"
#include "config.h"
#include "drivers/display.h"
#include "drivers/imu.h"
#include "drivers/buttons.h"
#include "drivers/ldr.h"
#include "drivers/buzzer.h"
#include "services/game_engine.h"
/*#include "services/wifi_manager.h"
#include "services/power_manager.h"*/

// Protótipos das tasks (definidas em src/tasks/*.cpp)
void taskUI(void *pv);
void taskInput(void *pv);
void taskSensores(void *pv);
void taskJogo(void *pv);
void taskNet(void *pv);

void setup() {
    Serial.begin(115200);

    display_init();
    imu_init();
    buttons_init();
    ldr_init();
    buzzer_init();
    game_engine_init();
    /*wifi_manager_init();
    power_manager_init();*/

    xTaskCreatePinnedToCore(taskUI,      "UI",      4096, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskInput,   "Input",   2048, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskSensores,"Sensores",3072, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskJogo,    "Jogo",    4096, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskNet,     "Net",     4096, nullptr, 0, nullptr, 0);
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000)); // tudo roda nas tasks
}
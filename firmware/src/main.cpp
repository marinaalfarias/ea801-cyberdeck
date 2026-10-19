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

void taskUI(void *pv);
void taskInput(void *pv);
void taskSensores(void *pv);
void taskJogo(void *pv);
void taskNet(void *pv);

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CyberDeck-Tama...");

    xTaskCreatePinnedToCore(taskUI,       "UI",       4096, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskInput,    "Input",    2048, nullptr, 2, nullptr, 1);
    xTaskCreatePinnedToCore(taskSensores, "Sensores", 3072, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskJogo,     "Jogo",     4096, nullptr, 1, nullptr, 0);
    xTaskCreatePinnedToCore(taskNet,      "Net",      4096, nullptr, 0, nullptr, 0);

    display_init();
    imu_init();
    buttons_init();
    ldr_init();
    buzzer_init();
    game_engine_init();

    display_get().setTextSize(1);
    display_get().setCursor(0,0);
    display_get().println("Hello CyberDeck-Tama");
}

void loop(){
    game_engine_tick();
    delay (1000);
}
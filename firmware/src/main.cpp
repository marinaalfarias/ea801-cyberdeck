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

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CyberDeck-Tama...");

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
    delay (1000);
}
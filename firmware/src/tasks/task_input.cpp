#include <Arduino.h>
#include "drivers/buttons.h"
#include "services/game_engine.h"
#include "drivers/buzzer.h"

void taskInput(void *pv) {
    for (;;) {
        if (buttons_is_up_pressed()) {
            game_engine_alimentar(); // Dá comida
            buzzer_play_tone(1500, 50); // Bipe de confirmação
        }
        vTaskDelay(pdMS_TO_TICKS(20)); // Roda a cada 20ms
    }
}
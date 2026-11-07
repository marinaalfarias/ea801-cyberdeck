#include <Arduino.h>
#include "drivers/buttons.h"
#include "services/game_engine.h"
#include "drivers/buzzer.h"

#include <Arduino.h>
#include "drivers/buttons.h"
#include "services/game_engine.h"
#include "drivers/buzzer.h"

void taskInput(void *pv) {
    for (;;) {
        if (buttons_is_up_pressed()) {
            game_engine_alimentar();
            game_engine_recarregar(); // também recarrega a energia
            buzzer_play_tone(1500, 50);
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}
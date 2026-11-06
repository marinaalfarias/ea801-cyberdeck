#include "buttons.h"
#include "pins.h"
#include <Arduino.h>

void buttons_init() {
    pinMode(PIN_BTN_UP, INPUT_PULLUP); // Usa o pull-up interno
}

bool buttons_is_up_pressed() {
    // Lógica simples de debounce por software
    static unsigned long last_press = 0;
    if (digitalRead(PIN_BTN_UP) == LOW) {
        if (millis() - last_press > 200) { // 200ms de debounce
            last_press = millis();
            return true;
        }
    }
    return false;
}
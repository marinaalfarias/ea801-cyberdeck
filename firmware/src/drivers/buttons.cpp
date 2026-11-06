#include "drivers/buttons.h"
#include "pins.h"

#include <Adafruit_GFX.h>

void buttons_init() {
    pinMode(PIN_BTN_UP, INPUT_PULLUP);
    pinMode(PIN_BTN_DOWN, INPUT_PULLUP);
    pinMode(PIN_BTN_SELECT, INPUT_PULLUP);
}

bool button_A_pressed(){
    return digitalRead(PIN_BTN_UP) == LOW;
}

bool button_B_pressed(){
    return digitalRead(PIN_BTN_DOWN) == LOW;
}

bool button_C_pressed(){
    return digitalRead(PIN_BTN_SELECT) == LOW;
}

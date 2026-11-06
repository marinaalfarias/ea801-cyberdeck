#include "buzzer.h"
#include "pins.h"
#include <Arduino.h>

#define BUZZER_PWM_CHANNEL 0

void buzzer_init() {
    // Configura PWM para o buzzer (frequência inicial de 2000Hz, 8 bits)
    ledcSetup(BUZZER_PWM_CHANNEL, 2000, 8);
    ledcAttachPin(PIN_BUZZER, BUZZER_PWM_CHANNEL);
    buzzer_stop();
}

void buzzer_play_tone(int freq, int duration_ms) {
    ledcWriteTone(BUZZER_PWM_CHANNEL, freq);
    delay(duration_ms);
    buzzer_stop();
}

void buzzer_stop() {
    ledcWriteTone(BUZZER_PWM_CHANNEL, 0); // Frequência 0 para o som
}
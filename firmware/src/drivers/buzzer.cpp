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

// Toca uma sequência de notas: frequências e durações em arrays paralelos
void buzzer_melodia(const int* notas, const int* duracoes, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (notas[i] > 0) {
            ledcWriteTone(BUZZER_PWM_CHANNEL, notas[i]);
        } else {
            ledcWriteTone(BUZZER_PWM_CHANNEL, 0);
        }
        delay(duracoes[i]);
        ledcWriteTone(BUZZER_PWM_CHANNEL, 0);
        delay(30); // pausa curta entre notas
    }
}

void som_ovo() {
    int notas[]     = { 523, 0, 523, 0, 659, 0 };
    int duracoes[]  = { 150, 50, 150, 50, 200, 100 };
    buzzer_melodia(notas, duracoes, 6);
}
void som_chocando() {
    int notas[]     = { 1000, 0, 1000, 0, 1000, 0 };
    int duracoes[]  = { 80, 80, 80, 80, 80, 100 };
    buzzer_melodia(notas, duracoes, 6);
}
void som_triste() {
    int notas[]     = { 659, 523, 440, 349 }; // Mi, Dó, Lá, Fá
    int duracoes[]  = { 200, 200, 250, 300 };
    buzzer_melodia(notas, duracoes, 4);
}
void som_bravo() {
    int notas[]     = { 300, 0, 300, 0, 300 }; 
    int duracoes[]  = { 100, 80, 100, 80, 200 };
    buzzer_melodia(notas, duracoes, 5);
}
void som_dormindo() {
    int notas[]     = { 523, 440, 392, 349, 0 };
    int duracoes[]  = { 300, 300, 300, 400, 200 };
    buzzer_melodia(notas, duracoes, 5);
}
void som_morto() {
    int notas[]     = { 440, 349, 262, 196, 0 };
    int duracoes[]  = { 300, 300, 400, 500, 300 };
    buzzer_melodia(notas, duracoes, 5);
}
void som_feliz() {
    int notas[]     = { 523, 659, 784, 1046 }; // Dó, Mi, Sol, Dó agudo
    int duracoes[]  = { 100, 100, 100, 200 };
    buzzer_melodia(notas, duracoes, 4);
}
#include <Arduino.h>

#define BUZZER_PIN 14

// Notas musicais para criar melodias (frequências em Hz)
#define NOTE_C5  523
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_C6  1047
#define NOTE_A5  880

void somClique() {
  tone(BUZZER_PIN, 1000, 30); // Beep bem curto (1000 Hz por 30ms)
}

void somFeliz() {
  // Arpejo rápido ascendente
  tone(BUZZER_PIN, NOTE_C5, 80);
  delay(90);
  tone(BUZZER_PIN, NOTE_E5, 80);
  delay(90);
  tone(BUZZER_PIN, NOTE_G5, 80);
  delay(90);
  tone(BUZZER_PIN, NOTE_C6, 150);
  delay(160);
}

void somAlerta() {
  // Som duplo de atenção (alerta de fome/sono)
  tone(BUZZER_PIN, NOTE_A5, 120);
  delay(150);
  tone(BUZZER_PIN, NOTE_A5, 120);
  delay(150);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  // Toca o som de inicialização ao ligar a placa
  somFeliz();
}


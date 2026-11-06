#include "ldr.h"
#include "pins.h"

void ldr_init() {
    pinMode(PIN_LDR, INPUT);
    analogReadResolution(12); // Resolução de 12 bits (0-4095)
}

int ldr_get_value() {
    return analogRead(PIN_LDR);
}

bool ldr_is_dark() {
    // Ajuste o valor 2000 conforme o seu circuito (resistor de 1k ou 10k)
    return analogRead(PIN_LDR) > 2000; 
}
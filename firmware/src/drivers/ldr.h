#pragma once
#include <Arduino.h>

void ldr_init();
int ldr_get_value(); // Retorna de 0 a 4095
bool ldr_is_dark();  // Retorna true se estiver escuro  
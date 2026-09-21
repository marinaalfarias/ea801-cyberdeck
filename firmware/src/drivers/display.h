#pragma once
#include <Adafruit_SSD1306.h>

void display_init();
Adafruit_SSD1306& display_get();
void display_clear();
void display_flush();
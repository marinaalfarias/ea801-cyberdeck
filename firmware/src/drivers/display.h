#pragma once

#include <Adafruit_ST7735.h>

void display_init();
Adafruit_ST7735& display_get();
void display_clear();
void display_flush();
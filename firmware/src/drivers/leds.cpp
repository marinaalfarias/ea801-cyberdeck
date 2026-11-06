#include <Adafruit_GFX.h>

#include "drivers/leds.h"

#define ESP32_RGB     48
// #define LED_RGB_1


void led_init(){
    pinMode(ESP32_RGB, OUTPUT);
    neopixelWrite(ESP32_RGB, 0, 0, 0);
}


void set_esp32_rgb(uint16_t r, uint16_t g, uint16_t b) {
    neopixelWrite(ESP32_RGB, r, g, b);
    return;
}

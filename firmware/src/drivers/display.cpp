#include "display.h"
#include "pins.h"
#include <Wire.h>

static Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void display_init() {
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.display();
}

Adafruit_SSD1306& display_get() { return display; }
void display_clear() { display.clearDisplay(); }
void display_flush() { display.display(); }
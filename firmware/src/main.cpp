#include <Adafruit_GFX.h>


#include "drivers/leds.h"
#include "drivers/buttons.h"
#include "drivers/display.h"
#include "drivers/buzzer.h"
#include "drivers/frames_upper.h"


void setup() {

  led_init();
  buttons_init();
  display_init();

}

void loop() {

  
  if (button_A_pressed()) {
    set_esp32_rgb(20, 0, 0);
    somClique();
    delay(200); // Debounce simples
    
  }
  else if (button_B_pressed()) {
    set_esp32_rgb(0, 20, 0);
    
  }
  else if (button_C_pressed()) {
    set_esp32_rgb(0, 0, 20);
    
  }
  else {
    set_esp32_rgb(0, 0, 0);
  }

  delay(20);
}
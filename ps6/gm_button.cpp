#include <Arduino.h>
#include "gm_button.h"


GMButton::GMButton(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  //digitalWrite(_pin, HIGH);
}


bool GMButton::isButtonPressed() {
  if (digitalRead(_pin) == LOW) {
    return true;
  } else {
    return false;
  }
}


void GMButton::waitButtonRelease() {
  delay(10); // de
  while (digitalRead(_pin) == LOW);
  delay(10); // de
}


int GMButton::waitButtonAction(int alt_pin_1, int alt_pin_2) {
  delay(10); // debounce button press
  int action = NO_ACTION;
  while (true) {
    if (digitalRead(_pin) == HIGH) {
      return BUTTON_RELEASE;
    } else if (alt_pin_1 > 0 && digitalRead(alt_pin_1) == LOW) {
      delay(10);
      while (digitalRead(alt_pin_1) == LOW);
      delay(10);
      return BUTTON_ALT_1;
    } else if (alt_pin_2 > 0 && digitalRead(alt_pin_2) == LOW) {
      delay(10);
      while (digitalRead(alt_pin_2) == LOW);
      delay(10);
      return BUTTON_ALT_2;
    }
  }
}
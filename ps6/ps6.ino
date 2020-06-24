#include <Arduino.h>
#include "mastermind.h"
#include "lcd_wrapper.h"


void setup() {

  randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));

  lcd_init();
  leds_init();
}


void loop() {
  lcd_clear();

  char *kod = generate_code(false, POCET_KOLIKOV);
  play_game(kod);
  while (true);
}
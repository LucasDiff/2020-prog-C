#include "mastermind.h"
#include <Arduino.h>




void setup() {
  randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));

  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.print("Ty to zvladnes!");

  pinMode(LED_BLUE_1, OUTPUT);
  pinMode(LED_BLUE_2, OUTPUT);
  pinMode(LED_BLUE_3, OUTPUT);
  pinMode(LED_BLUE_4, OUTPUT); 
  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_RED_2, OUTPUT); 
  pinMode(LED_RED_3, OUTPUT);
  pinMode(LED_RED_4, OUTPUT);
  turn_leds_off();
}


void loop() {
  lcd.setCursor(0, 1);
  lcd.print(" ");

  char *kod = generate_code(false, 4);
  play_game(kod);
  while (true);
}
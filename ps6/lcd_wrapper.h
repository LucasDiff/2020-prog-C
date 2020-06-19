#ifndef _LCD_WRAPPER_H
#define _LCD_WRAPPER_H

#define BTN_1_PIN       0
#define BTN_2_PIN       1
#define BTN_3_PIN       2
#define BTN_4_PIN       3
#define BTN_ENTER_PIN   4

#define NO_ACTION      0
#define BUTTON_RELEASE 1
#define BUTTON_ALT_1   2
#define BUTTON_ALT_2   3


class GMButton {
  int _pin;
public:
  GMButton(int pin);
  bool isButtonPressed();
  void waitButtonRelease();
  int waitButtonAction(int alt_pin_1, int alt_pin_2);
};

#endif
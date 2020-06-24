#ifndef _GM_BUTTON_H
#define _GM_BUTTON_H

#define NO_ACTION      0
#define BUTTON_RELEASE 1
#define BUTTON_ALT_1   2
#define BUTTON_ALT_2   3


class GMButton {
  int _pin;
public:
  /**
   * Inicializacia pinu kde je tlacidlo
   */
  GMButton(int pin);

  /**
   * Overi ci je tlacidlo stlacene (LOW hodnota na pine). Vrati true/false.
   */
  bool isButtonPressed();

  /**
   * Caka pokial je tlacidlo stlacene.
   * Riesi problem s kmitanim kontaktu tlacidla (debounce).
   */
  void waitButtonRelease();

  /**
   * Rozsirena funkcionalita cakania na pustenie tlacidla,
   * ktora este navyse detekuje sucasne stlacenie jedneho
   * z dvoch moznych alternativnych tlacidiel (na pinoch alt_pin_1 a 2).
   * Ked su hodnoty tychto dvoch alt parametrov mensie ako 0, tak su ignorovane.
   */
  int waitButtonAction(int alt_pin_1, int alt_pin_2);
};

#endif

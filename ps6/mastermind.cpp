#include "mastermind.h"
#include "lcd_wrapper.h"
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

 
// Objekty pre LCD a tlacidla  
LiquidCrystal_I2C lcd(0x27,16,2);
GMButton btn[4] {BTN_1_PIN, BTN_2_PIN, BTN_3_PIN, BTN_4_PIN};
GMButton btn_enter = GMButton(BTN_ENTER_PIN);


void play_game(char *kod) {
  char guess[4];
  guess[0] = 0;
  guess[1] = 0;
  guess[2] = 0;
  guess[3] = 0;

  int peg_a = 0;
  int peg_b = 0;
  bool koniec = false;
  int hist_posn = 0;
  int hist_size = 0;
  char *history[MAX_MOVES];
  int status = STATUS_PLAY;

  turn_leds_off();

  while (!koniec) {
    if (status == STATUS_PLAY) {
      render_guess(guess);
      //reveal_kod(kod);
    }

    for (int i = 0; i < 4; i++) {
      if (btn[i].isButtonPressed()) {
        int alt_pin_1 = i == 0 ? BTN_3_PIN : -1;
        int alt_pin_2 = i == 0 ? BTN_4_PIN : -1;
        int action = btn[i].waitButtonAction(alt_pin_1, alt_pin_2);
        if (action == BUTTON_RELEASE) {
          if (status == STATUS_PLAY) {
            turn_leds_off();
            if (guess[i] != 9) {
              guess[i]++;
            } else {
              guess[i] = 0;
            }
          } else {
            status = STATUS_PLAY;
            lcd.setCursor(0, 1);
            lcd.print("                ");
            turn_leds_off();
          }
        } else if (hist_size > 0 && action == BUTTON_ALT_1) {
          if (status == STATUS_PLAY) {
            hist_posn = hist_size - 1;
          } else {
            if (hist_posn > 0) {
              hist_posn--;
            }
          }
          status = STATUS_HIST;
          render_history(kod, history, hist_posn);
        } else if (hist_size > 0 && action == BUTTON_ALT_2) {
          if (status == STATUS_PLAY) {
            hist_posn = hist_size - 1;
          } else {
            if (hist_posn < hist_size - 1) {
              hist_posn++;
            }
          }
          status = STATUS_HIST;
          render_history(kod, history, hist_posn);
        }
      }

      if (btn_enter.isButtonPressed()) {
        btn_enter.waitButtonRelease();

        char *hist_entry = (char*) malloc(sizeof(char) * 4);
        for (int h = 0; h < 4; h++) {
          hist_entry[h] = guess[h];
        }
        history[hist_size] = hist_entry;
        hist_size++;
        
        get_score(kod, guess, &peg_a, &peg_b);
        turn_leds_on();
        delay(50);
        turn_leds_off();
        render_leds(peg_a, peg_b);
        delay(500);

        if (peg_a == 4) {
          led_effect();
          led_effect();
          led_effect();
          delay(2000);
          lcd.setCursor(0,0);
          lcd.print("WOOOW, dobry si!"); 
          lcd.setCursor(0,1);
          lcd.print("Restart Arduino"); 
          koniec = true;
        }

        if (hist_size == MAX_MOVES) {
          for (int b = 0; b < 10; b++) {
            turn_red_leds_on();
            delay(100);
            turn_leds_off();
            delay(100);
          }
          lcd.setCursor(0, 0);
          lcd.print("Si to nezvladol ");
          lcd.setCursor(0, 1);
          lcd.print("  >>  :-(  <<   ");
          koniec = true;
        }
      }
    }
  }
}


void turn_leds_off(){
  digitalWrite(LED_RED_1,LOW);
  digitalWrite(LED_BLUE_1,LOW);
  digitalWrite(LED_RED_2,LOW);
  digitalWrite(LED_BLUE_2,LOW);
  digitalWrite(LED_RED_3,LOW);
  digitalWrite(LED_BLUE_3,LOW);
  digitalWrite(LED_RED_4,LOW);
  digitalWrite(LED_BLUE_4,LOW);
}

void turn_leds_on(){
  digitalWrite(LED_RED_1,HIGH);
  digitalWrite(LED_BLUE_1,HIGH);
  digitalWrite(LED_RED_2,HIGH);
  digitalWrite(LED_BLUE_2,HIGH);
  digitalWrite(LED_RED_3,HIGH);
  digitalWrite(LED_BLUE_3,HIGH);
  digitalWrite(LED_RED_4,HIGH);
  digitalWrite(LED_BLUE_4,HIGH);
}

void turn_red_leds_on(){
  digitalWrite(LED_RED_1,HIGH);
  digitalWrite(LED_RED_2,HIGH);
  digitalWrite(LED_RED_3,HIGH);
  digitalWrite(LED_RED_4,HIGH);
}


void led_effect() {
  turn_leds_off();
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED_BLUE_1 + i, HIGH);
    delay(60);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED_BLUE_1 + i, LOW);
    delay(60);
  }
}


char* generate_code(bool repeat, int length){
    if(repeat == false && length > 10){
      return NULL;
    }
    if(length < 1){
      return NULL;
    }
    char* kod = (char*) malloc(sizeof(char) * length); 
    if (repeat == true){
        for (int opakujuce=0; opakujuce<length; opakujuce++){
            kod[opakujuce] = (char) random(10);
        }
    }
    else{
        for (int neopakujuce=0; neopakujuce<length; neopakujuce++){
            int docasne = random(10);
            for (int a = 0; a < neopakujuce; a++){
                if (kod[a] == docasne){
                    docasne = (char) random(10);
                    a = 0;
                }
            }
            kod[neopakujuce] = (char) docasne;
        }
    }
    return kod; 
}


void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){ 
    int pokus_a = 0;
    int pokus_b = 0;
    *peg_a = 0; 
    *peg_b = 0; 
    
    for (pokus_a = 0; pokus_a < 4; pokus_a++){
      if (secret[pokus_a] == guess[pokus_a]) {
        (*peg_a)++;
      }
      else{
          for (pokus_b = 0; pokus_b < 4; pokus_b++) { 
              if (secret[pokus_a] == guess[pokus_b]) { 
                  (*peg_b)++;
                   break;  
               }
           }  
      }  
    }
}


void render_leds(const int peg_a, const int peg_b) {
  int ledky = 0;
  turn_leds_off(); 
  for (ledky = 1; ledky <= 4; ledky++) {
    if (ledky <= peg_a) { 
      switch (ledky) {
        case 1:
          digitalWrite(LED_RED_1, HIGH);
          break;
        case 2:
          digitalWrite(LED_RED_2, HIGH);
          break;
        case 3:
          digitalWrite(LED_RED_3, HIGH);
          break;
        case 4:
          digitalWrite(LED_RED_4, HIGH);
          break;
      }
    }
    else if((ledky - peg_a) <= peg_b ){ 
      switch (ledky) {
        case 1:
          digitalWrite(LED_BLUE_1, HIGH);
          break;
        case 2:
          digitalWrite(LED_BLUE_2, HIGH);
          break;
        case 3:
          digitalWrite(LED_BLUE_3, HIGH);
          break;
        case 4:
          digitalWrite(LED_BLUE_4, HIGH);
          break;
      }
    }
  }
}


void render_history(char* secret, char** history, const int entry_nr) { 
     char* pom = (char*) malloc(sizeof(char) * 4);
    
     char* kod_historie = (char*) malloc(sizeof(char) * 4); 
      
     int peg_a, peg_b;
      
     for(int i = 0; i < 4; i++){ 
       kod_historie[i] = char('0' + *(*(history+entry_nr)+i)); 
     }
     for(int i = 0; i < 4; i++){ 
        pom[i] = char('0' + secret[i]);
     }
  
     get_score(pom, kod_historie, &peg_a, &peg_b); 
     render_leds(peg_a, peg_b);
     int a = entry_nr;
     lcd.setCursor(0,1);
     lcd.print("                ");
     lcd.setCursor(0,1);
     lcd.print(0); 
     lcd.print(a + 1);
     lcd.setCursor(2,1);
     lcd.print(":");
     for(int i = 0; i < 4; i++){  
        lcd.setCursor(3+i,1); 
        lcd.print(kod_historie[i]);
     }
     lcd.setCursor(10,1); 
     lcd.print(peg_a);
     lcd.print("A");
     lcd.setCursor(12,1); 
     lcd.print(peg_b); 
     lcd.print("B");

     free(kod_historie);
     free(pom);
}

void render_guess(char *guess) {
  lcd.setCursor(0, 1);
  char* str = (char*) malloc(sizeof(char) * 5); 
  str[0] = guess[0] + '0';
  str[1] = guess[1] + '0';
  str[2] = guess[2] + '0';
  str[3] = guess[3] + '0';
  str[4] = '\0';
  lcd.print(str);
  free(str);
}

void reveal_kod(char *kod) {
  lcd.setCursor(5, 1);
  char* str = (char*) malloc(sizeof(char) * 5); 
  str[0] = kod[0] + '0';
  str[1] = kod[1] + '0';
  str[2] = kod[2] + '0';
  str[3] = kod[3] + '0';
  str[4] = '\0';
  lcd.print(str);
  free(str);
}
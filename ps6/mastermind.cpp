#include <Arduino.h>
#include "mastermind.h"
#include "lcd_wrapper.h"
#include "gm_button.h"
 

void play_game(char *secret) {
  // Objekty tlacidiel
  GMButton btn[POCET_KOLIKOV] {BTN_1_PIN, BTN_2_PIN, BTN_3_PIN, BTN_4_PIN};
  GMButton btn_enter = GMButton(BTN_ENTER_PIN);

  char guess[POCET_KOLIKOV];
  for (int i = 0; i < POCET_KOLIKOV; i++) {
    guess[i] = 0;    
  }

  int peg_a = 0;
  int peg_b = 0;
  int poc = 0;
  bool koniec = false;
  int hist_posn = 0;
  int hist_size = 0;
  char *history[MAX_MOVES];
  int status = STATUS_PLAY;

  turn_off_leds();
      lcd_init();
  while (!koniec) {
    if (status == STATUS_PLAY) {
      render_guess(guess); 
      reveal_secret(secret);
    }

    for (int i = 0; i < POCET_KOLIKOV; i++) {
      if (btn[i].isButtonPressed()) {
        int alt_pin_1 = i == 0 ? BTN_3_PIN : -1;
        int alt_pin_2 = i == 0 ? BTN_4_PIN : -1;
        int action = btn[i].waitButtonAction(alt_pin_1, alt_pin_2);
        if (action == BUTTON_RELEASE) {
          if (status == STATUS_PLAY) {
            turn_off_leds();
            if (guess[i] != 9) {
              guess[i]++;
            } else {
              guess[i] = 0;
            }
          } else if (status == STATUS_HIST) {
            status = STATUS_PLAY;
            lcd_print_at(0, 1, "                ");
            turn_off_leds();
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
          render_history(secret, history, hist_posn);
        } else if (hist_size > 0 && action == BUTTON_ALT_2) {
          if (status == STATUS_PLAY) {
            hist_posn = hist_size - 1;
          } else {
            if (hist_posn < hist_size - 1) {
              hist_posn++;
            }
          }
          status = STATUS_HIST;
          render_history(secret, history, hist_posn);
        }
      }

      if (btn_enter.isButtonPressed()) {
        btn_enter.waitButtonRelease();
        poc++;
        char poc_str[3];
        poc_str[0] = poc >= 10 ? '1' : '0';
        poc_str[1] = '0' + (poc % 10);
        poc_str[2] = '\0';
        lcd_print_at(14, 1, poc_str);

        char *hist_entry = (char*) malloc(sizeof(char) * POCET_KOLIKOV);
        for (int h = 0; h < POCET_KOLIKOV; h++) {
          hist_entry[h] = guess[h];
        }
        history[hist_size] = hist_entry;
        hist_size++;
        
        get_score(secret, guess, &peg_a, &peg_b);
        turn_on_leds();
        delay(50);
        turn_off_leds();
        render_leds(peg_a, peg_b);
        delay(500);

        // Test na uspesne ukoncenie hry
        if (peg_a == POCET_KOLIKOV) {
          for( int g = 10; g >= poc; g--) {
            led_effect();
          }
          delay(1500);
          lcd_print_at(0, 0, "WOOOW, dobry si!"); 
          lcd_print_at(0, 1, "Pokus cislo : "); 
          koniec = true;
          break;
        }

        // Test na neuspesne ukoncenie hry
        if (hist_size == MAX_MOVES) {
          for (int b = 0; b < 10; b++) {
            turn_on_red_leds();
            delay(100);
            turn_off_leds();
            delay(100);
          }
          lcd_print_at(0, 0, "Nezvladol si to ");
          lcd_print_at(0, 1, "Kod :");
          reveal_secret(secret);
          koniec = true;
          break;
        }
      }
    }
  }
}


void turn_off_leds() {
  digitalWrite(LED_RED_1,LOW);
  digitalWrite(LED_BLUE_1,LOW);
  digitalWrite(LED_RED_2,LOW);
  digitalWrite(LED_BLUE_2,LOW);
  digitalWrite(LED_RED_3,LOW);
  digitalWrite(LED_BLUE_3,LOW);
  digitalWrite(LED_RED_4,LOW);
  digitalWrite(LED_BLUE_4,LOW);
}


void turn_on_leds() {
  digitalWrite(LED_RED_1,HIGH);
  digitalWrite(LED_BLUE_1,HIGH);
  digitalWrite(LED_RED_2,HIGH);
  digitalWrite(LED_BLUE_2,HIGH);
  digitalWrite(LED_RED_3,HIGH);
  digitalWrite(LED_BLUE_3,HIGH);
  digitalWrite(LED_RED_4,HIGH);
  digitalWrite(LED_BLUE_4,HIGH);
}


void turn_on_red_leds() {
  digitalWrite(LED_RED_1,HIGH);
  digitalWrite(LED_RED_2,HIGH);
  digitalWrite(LED_RED_3,HIGH);
  digitalWrite(LED_RED_4,HIGH);
}


void led_effect() {
  turn_off_leds();
  for (int i = 0; i < 2 * POCET_KOLIKOV; i++) {
    digitalWrite(LED_BLUE_1 + i, HIGH);
    delay(60);
  }
  for (int i = 0; i < 2 * POCET_KOLIKOV; i++) {
    digitalWrite(LED_BLUE_1 + i, LOW);
    delay(60);
  }
}


char* generate_code(bool repeat, int length) {
    if(repeat == false && length > MAX_MOVES) {
      return NULL;
    }
    if(length < 1) {
      return NULL;
    }
    char* kod = (char*) malloc(sizeof(char) * length); 
    if (repeat == true){
        for (int opakujuce = 0; opakujuce < length; opakujuce++) {
            kod[opakujuce] = (char) random(10);
        }
    }
    else {
        for (int neopakujuce=0; neopakujuce < length; neopakujuce++) {
            int docasne = random(10);
            for (int a = 0; a < neopakujuce; a++) {
                if (kod[a] == docasne) {
                    docasne = (char) random(10);
                    a = 0;
                }
            }
            kod[neopakujuce] = (char)docasne;
        }
    }
    return kod; 
}


void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b) { 
    int pokus_a = 0;
    int pokus_b = 0;
    *peg_a = 0; 
    *peg_b = 0; 
    
    for (pokus_a = 0; pokus_a < POCET_KOLIKOV; pokus_a++){
      if (secret[pokus_a] == guess[pokus_a]) {
        (*peg_a)++;
      }
      else{
          for (pokus_b = 0; pokus_b < POCET_KOLIKOV; pokus_b++) { 
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
  turn_off_leds(); 
  for (ledky = 1; ledky <= POCET_KOLIKOV; ledky++) {
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
     char* pom = (char*) malloc(sizeof(char) * POCET_KOLIKOV);
    
     char* kod_historie = (char*) malloc(sizeof(char) * POCET_KOLIKOV);
      
     int peg_a, peg_b;
      
     for(int i = 0; i < POCET_KOLIKOV; i++) { 
       kod_historie[i] = char('0' + *(*(history + entry_nr) + i)); 
     }
     for(int i = 0; i < POCET_KOLIKOV; i++) { 
        pom[i] = char('0' + secret[i]);
     }
  
     get_score(pom, kod_historie, &peg_a, &peg_b); 
     render_leds(peg_a, peg_b);
     int a = entry_nr;
     lcd_print_at(0, 1, "                ");
     lcd_print_at(0, 1, '0'); 
     lcd_print('0' + a + 1);
     lcd_print_at(2, 1, ":");
     for(int i = 0; i < POCET_KOLIKOV; i++){  
        lcd_print_at(3 + i, 1, kod_historie[i]);
     }
     lcd_print_at(10, 1, '0' + peg_a);
     lcd_print("A");
     lcd_print_at(12, 1, '0' + peg_b); 
     lcd_print("B");

     free(kod_historie);
     free(pom);
}


void leds_init() {
  pinMode(LED_BLUE_1, OUTPUT);
  pinMode(LED_BLUE_2, OUTPUT);
  pinMode(LED_BLUE_3, OUTPUT);
  pinMode(LED_BLUE_4, OUTPUT); 
  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_RED_2, OUTPUT); 
  pinMode(LED_RED_3, OUTPUT);
  pinMode(LED_RED_4, OUTPUT);  
  turn_off_leds();
}


void render_guess(char *guess) {
  lcd_set_cursor(0, 1);
  char* str = (char*) malloc(sizeof(char) * (POCET_KOLIKOV + 1));
  for (int i = 0; i < POCET_KOLIKOV; i++) {
    str[i] = guess[i] + '0';
  }
  str[POCET_KOLIKOV] = '\0';
  lcd_print(str);
  free(str);
}


void reveal_secret(char *secret) {
  lcd_set_cursor(5, 1);
  char* str = (char*) malloc(sizeof(char) * (POCET_KOLIKOV + 1)); 
  for (int i = 0; i < POCET_KOLIKOV; i++) {
    str[i] = secret[i] + '0';
  }
  str[POCET_KOLIKOV] = '\0';
  lcd_print(str);
  free(str);
}
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "lcd_wrapper.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);


void lcd_init(){
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.print("Ty to zvladnes!");
}

void lcd_clear(){
  lcd.clear();
}


void lcd_set_cursor(int column, int row){
  lcd.setCursor(column, row);
}


void lcd_print(const char* text){
  lcd.print(text);
}

void lcd_print(char c){
  lcd.print(c);
}

void lcd_print_at(int column, int row, const char* text){
    lcd_set_cursor(column, row);
    lcd_print(text);
}

void lcd_print_at(int column, int row, char c) {
    lcd_set_cursor(column, row);
    lcd_print(c);
}
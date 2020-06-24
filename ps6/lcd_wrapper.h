#ifndef _LCD_H
#define _LCD_H

/**
 * Initialize LCD
 * 
 * Everything you need to initialize your LCD display, place here.
 * This function should be called in function setup().
 */
void lcd_init();


/**
 * Clears the LCD display
 * 
 * Clears content of the LCD display. After the call is display empty.
 */
void lcd_clear();


/**
 * Set cursor to given posititon
 * 
 * Sets cursor to given position based on x and y coordinates.
 * @param column the column
 * @param row the row
 */
void lcd_set_cursor(int column, int row);


/**
 * Print text on LCD display
 * 
 * Prints the givent text on the display on the current
 * cursor position.
 * @param text the text to print
 */
void lcd_print(const char* text);

void lcd_print(char c);


/**
 * Set cursor to given positition and print text
 * 
 * Sets the cursor to given position based on x and y coorindates
 * and then prints the given text.
 * @param column the column
 * @param row the row
 * @param text the text to print
 */
void lcd_print_at(int column, int row, const char* text);

void lcd_print_at(int column, int row, char c);

#endif

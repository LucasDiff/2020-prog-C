#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#define LED_BLUE_1      6
#define LED_RED_1       7
#define LED_BLUE_2      8
#define LED_RED_2       9
#define LED_BLUE_3      10
#define LED_RED_3       11
#define LED_BLUE_4      12
#define LED_RED_4       13

#define MAX_MOVES       10

#define STATUS_PLAY     1
#define STATUS_HIST     2


/**
 * Generate secret code
 * 
 * Generates secret code, which consists from digits only as a string. 
 * No two digits in the code combination can be same! Only if the repeat
 * parameter is set to true.
 * The length of generated code is set by the parameter length. If the given
 * parameter is less than 1, function will generate no code and returns NULL.
 * @param repeat if set to true, numbers in the generated code can repeat
 * @param length the length of the code
 * @return Pointer to the random generated code as string of given length. If length param is less than 1, return NULL.
 */
char* generate_code(bool repeat, int length);


/**
 * Game loop
 *
 * This is the main game loop. Function is called with the secret combination and
 * ends, when the combination is found or when the player runs out of the attempts.
 * @param secret reference to the secret combination
 */
void play_game(char* secret);


/**
 * Renders the RGB leds based on the guessed combination
 *
 * Lights up RGB leds with propper colors based on the current guessed combination.
 * Red color is for guessed number on correct position and blue number is for
 * guessed number on incorrect posititoin.
 * @param peg_a number of guessed digits on correct position
 * @param peg_b number of guessed digits on incorrect position
 */
void render_leds(const int peg_a, const int peg_b);


/**
 * Turns all RGB leds off
 */
void turn_leds_off();


/**
 * Renders history
 *
 * Renders line of a history defined by the parameter entry_nr on the display.
 * @param secret reference to the secret combination
 * @param history list (array) of history entries
 * @param entry_nr index of history entry to render
 */
void render_history(char* secret, char** history, const int entry_nr);


/**
 * Returns score for the given guess
 *
 * @param secret the pointer to the secret code
 * @param guess the pointer to the current guess
 * @param peg_a output parameter to get number of As for current guess
 * * @param peg_b output parameter to get number of Bs for current guess
 */
void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b);

void play_game(char *kod);
void render_guess(char *guess);
void led_effect();
void turn_red_leds_on();

#endif
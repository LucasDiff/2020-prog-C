#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "k.c"
#include "k.h"
#include "hof.c"
#include "hof.h"
#include "ui.c"
#include "ui.h"

int main(){
struct game game = {
    .board = {
        {'A', 'A', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'}
    },
    .score = 1234
};

printf("is won: %d\n", is_game_won(game));

printf("is move possible: %d\n", is_move_possible(game));
printf("pismeno je : %c\n",  game.board[0][3]);
bool result = update(&game, 0, -1);
printf("pismeno je : %c\n",  game.board[0][3]);
printf("je : %d\n", result);
printf("score is : %d\n", game.score);
return 0;
}
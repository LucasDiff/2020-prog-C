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
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'A'},
        {'B', 'C', 'D', 'E'}
    },
    .score = 0
};

printf("is won: %d\n", is_game_won(game));

printf("is move possible: %d\n", is_move_possible(game));

printf("is won: %d\n", is_game_won(game));

printf("is move possible: %d\n", is_move_possible(game));

return 0;
}
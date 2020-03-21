#include "k.c"
#include "k.h"
#include "hof.c"
#include "hof.h"
#include "ui.c"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
int v = 0;
if (v == 1){
return 0;
}
struct game game = {
    .board = {
        {'A', 'D', 'I', 'H'},
        {'C', 'J', 'J', 'B'},
        {'G', ' ', 'H', 'I'},
        {'H', ' ', 'A', ' '}
    },
    .score = 0
};

bool result5 = is_move_possible(game);
render(game);
add_random_tile(&game);

bool result = update(&game, -1, 0);
printf("Update %d \n",result);
for (int c = 0; c < 4; c++){
    for (int v = 0; v < 4; v++){
        printf("%c ", game.board[c][v]);
        }
        printf("\n");
    }
    struct player player = {.name="marek", .score=100};
    struct player hof[10] = {
    {.score= 2000, .name="LOL"},
    {.score= 1800, .name="LOL"},
    {.score= 1700, .name="LOL"},
    {.score= 1000, .name="Ja"},
    {.score= 700, .name="Ty"},
    {.score= 560, .name="On"},
    {.score= 550, .name="Ona"}
    };
    int velkost=7;

    bool result3 = save(hof, load(hof));
    bool result4 = is_game_won(game);
    bool result2 = add_player(hof, &velkost,player);

    printf("is game won %d \n",result4);
    printf("is move possible  %d \n",result5);
    printf("Add player %d \n",result2);
    printf("save %d \n",result3);

    printf("%d \n",velkost);
    for (int i = 0; i <velkost+1;i++){
            printf("%s %d \n", hof[i].name, hof[i].score);
            }
    return 0;
}
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "k.h"

bool is_game_won(const struct game game){
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 0; sirka <= 3; sirka++){
            if (game.board[vyska][sirka] == 'K'){
                return true;
                }
}
}
    return false;
}

bool is_move_possible(const struct game game){
    for (int vyska = 0; vyska < 3; vyska++){
        for (int sirka = 0; sirka < 3; sirka++){
            if (game.board[vyska][sirka] == ' '){
                return true;
            }
            if (game.board[vyska][sirka] == 'K'){
               return false;
            }
            if (game.board[vyska][sirka] == game.board[vyska + 1][sirka]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska][sirka + 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska - 1][sirka]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska][sirka - 1]){
                return true;
            }
}
}
    return false;
}
bool update(struct game *game, int dy, int dx){
    if (dy == dx){
    return false;
    }
    if (dy + dx == 0){
    return false;
    }
    double cislo = 0;
    if (dx == 1){
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 0; sirka < 3; sirka++){
            int nasobitel = 0;
            int medzi = 0;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka + 1] == ' '){
                    game->board[vyska][sirka + 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    }
                }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska][sirka + 1] && game->board[vyska][sirka + 1] == game->board[vyska][sirka + 2] && game->board[vyska][sirka + 1] != game->board[vyska][sirka + 3]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska][sirka + 1] = ' ';
                medzi = game->board[vyska][sirka + 2] + 1;
                game->board[vyska][sirka + 3] = medzi;
                nasobitel = game->board[vyska][sirka + 3] - 64;
                cislo += pow(2, nasobitel);
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka] == game->board[vyska][sirka+1]){
                    game->board[vyska][sirka] = ' ';
                    medzi = game->board[vyska][sirka + 1] + 1;
                    game->board[vyska][sirka + 1] = medzi;
                    nasobitel = game->board[vyska][sirka + 1] - 64;
                    cislo += pow(2, nasobitel);
                    }
                    }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka + 1] == ' '){
                    game->board[vyska][sirka + 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    }
                }
            if ( game->board[vyska][1] != ' ' && game->board[vyska][1] == game->board[vyska][3] && game->board[vyska][2] == ' '){
            game->board[vyska][2] = game->board[vyska][1];
            game->board[vyska][1] = ' ';
            }
            }
        }
    }
    game->score += cislo;
    return true;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "k.h"


bool is_game_won(const struct game game){
    for (int vyska = 0; vyska < 3; vyska++){
        for (int sirka = 0; sirka < 3; sirka++){
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
            if (game.board[vyska][sirka] == game.board[vyska + 1][sirka + 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska][sirka + 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska + 1][sirka - 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska - 1][sirka]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska - 1][sirka + 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska - 1][sirka - 1]){
                return true;
            }
            if (game.board[vyska][sirka] == game.board[vyska][sirka - 1]){
                return true;
            }
}
}
    return false;
}
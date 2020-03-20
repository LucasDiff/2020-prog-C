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
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 0; sirka <= 3; sirka++){
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
    char pole[11]="ABCDEFGHIJK";
    if (dy == dx){
    return false;
    }
    if (dy + dx == 0){
    return false;
    }
    int cislo = 0;
    if (dx == 1){
    int v = 0;
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 0; sirka < 3; sirka++){
            v = 0;
            int nasobitel = 1;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka + 1] == ' '){
                    game->board[vyska][sirka + 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    }
                }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska][sirka + 1] && game->board[vyska][sirka + 1] == game->board[vyska][sirka + 2] && game->board[vyska][sirka + 1] != game->board[vyska][sirka + 3]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska][sirka + 1] = ' ';
                for (int c = 0; c < 11; c++){
                if (game->board[vyska][sirka + 2] == pole[c]){
                c = 11;
                }
                v++;
                }
                game->board[vyska][sirka + 3] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                cislo += nasobitel * 2;
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka] == game->board[vyska][sirka+1]){
                    game->board[vyska][sirka] = ' ';
                for (int c = 0; c < 11; c++){
                if (game->board[vyska][sirka + 1] == pole[c]){
                c = 11;
                }
                v++;
                }
                    game->board[vyska][sirka + 1] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                    cislo += nasobitel * 2;
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
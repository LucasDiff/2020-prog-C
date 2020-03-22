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
    if ( dy < -1){
    return false;
    }
    if ( dy > 1){
    return false;
    }
    if ( dx < -1){
    return false;
    }
    if ( dx > 1){
    return false;
    }
    int cislo = 0;
    if (dy == 1){
    int v = 0;
    int g = 0;
    for (int sirka = 0; sirka <= 3; sirka++){
        for (int vyska = 0; vyska < 3; vyska++){
            v = 0;
            int nasobitel = 1;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska + 1][sirka] == ' '){
                    game->board[vyska + 1][sirka] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska + 1][sirka] && game->board[vyska + 1][sirka] == game->board[vyska + 2][sirka] && game->board[vyska + 1][sirka] != game->board[vyska + 3][sirka]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska + 1][sirka] = ' ';
                g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska + 2][sirka] == pole[c]){
                c = 11;
                }
                v++;
                }
                game->board[vyska + 3][sirka] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                cislo += nasobitel * 2;
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka] == game->board[vyska + 1][sirka]){
                    game->board[vyska][sirka] = ' ';
                    g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska + 1][sirka] == pole[c]){
                c = 11;
                }
                v++;
                }
                    game->board[vyska + 1][sirka] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                    cislo += nasobitel * 2;
                    }
                    }
            if (game->board[vyska + 1][sirka] != ' ' && vyska <= 1){
                if (game->board[vyska + 2][sirka] == ' '){
                    game->board[vyska + 2][sirka] = game->board[vyska + 1][sirka];
                    game->board[vyska + 1][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska + 1][sirka] == ' '){
                    game->board[vyska + 1][sirka] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
            if (game->board[vyska + 1][sirka] != ' ' && vyska <= 1){
                if (game->board[vyska + 2][sirka] == ' '){
                    game->board[vyska + 2][sirka] = game->board[vyska + 1][sirka];
                    game->board[vyska + 1][sirka] = ' ';
                    g++;
                    }
                }
                }
            if ( game->board[1][sirka] != ' ' && game->board[1][sirka] == game->board[3][sirka] && game->board[2][sirka] == ' '){
            game->board[2][sirka] = game->board[1][vyska];
            game->board[1][sirka] = ' ';
            }
            }
        }
        if (g == 0){
        return false;
        }
    }
    if (dy == -1){
    int v = 0;
    int g = 0;
    for (int sirka = 0; sirka <= 3; sirka++){
        for (int vyska = 3; vyska > 0; vyska--){
            v = 0;
            int nasobitel = 1;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska - 1][sirka] == ' '){
                    game->board[vyska - 1][sirka] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska - 1][sirka] && game->board[vyska - 1][sirka] == game->board[vyska - 2][sirka] && game->board[vyska - 1][sirka] != game->board[vyska - 3][sirka]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska - 1][sirka] = ' ';
                g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska - 2][sirka] == pole[c]){
                c = 11;
                }
                v++;
                }
                game->board[vyska - 3][sirka] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                cislo += nasobitel * 2;
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka] == game->board[vyska - 1][sirka]){
                    game->board[vyska][sirka] = ' ';
                    g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska - 1][sirka] == pole[c]){
                c = 11;
                }
                v++;
                }
                    game->board[vyska - 1][sirka] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                    cislo += nasobitel * 2;
                    }
                    }
            if (game->board[vyska - 1][sirka] != ' ' && vyska >= 2){
                if (game->board[vyska - 2][sirka] == ' '){
                    game->board[vyska - 2][sirka] = game->board[vyska - 1][sirka];
                    game->board[vyska - 1][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska - 1][sirka] == ' '){
                    game->board[vyska - 1][sirka] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
            if (game->board[vyska - 1][sirka] != ' ' && vyska >= 2){
                if (game->board[vyska - 2][sirka] == ' '){
                    game->board[vyska - 2][sirka] = game->board[vyska - 1][sirka];
                    game->board[vyska - 1][sirka] = ' ';
                    g++;
                    }
                }
                }
            if ( game->board[2][sirka] != ' ' && game->board[2][sirka] == game->board[0][sirka] && game->board[1][sirka] == ' '){
            game->board[1][sirka] = game->board[2][sirka];
            game->board[2][sirka] = ' ';
            }
            }
        }
        if ( g == 0 ){
        return false;
        }
        }
    if (dx == 1){
    int v = 0;
    int g = 0;
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 0; sirka < 3; sirka++){
            v = 0;
            int nasobitel = 1;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka + 1] == ' '){
                    game->board[vyska][sirka + 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska][sirka + 1] && game->board[vyska][sirka + 1] == game->board[vyska][sirka + 2] && game->board[vyska][sirka + 1] != game->board[vyska][sirka + 3]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska][sirka + 1] = ' ';
                g++;
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
                    g++;
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
            if (game->board[vyska][sirka + 1] != ' ' && sirka <= 1){
                if (game->board[vyska][sirka + 2] == ' '){
                    game->board[vyska][sirka + 2] = game->board[vyska][sirka + 1];
                    game->board[vyska][sirka + 1] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka + 1] == ' '){
                    game->board[vyska][sirka + 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
            if (game->board[vyska][sirka + 1] != ' ' && sirka <= 1){
                if (game->board[vyska][sirka + 2] == ' '){
                    game->board[vyska][sirka + 2] = game->board[vyska][sirka + 1];
                    game->board[vyska][sirka + 1] = ' ';
                    g++;
                    }
                }
                }
            if ( game->board[vyska][1] != ' ' && game->board[vyska][1] == game->board[vyska][3] && game->board[vyska][2] == ' '){
            game->board[vyska][2] = game->board[vyska][1];
            game->board[vyska][1] = ' ';
            }
            }
        }
        if (g == 0){
        return false;
        }
    }
    if (dx == -1){
    int v = 0;
    int g = 0;
    for (int vyska = 0; vyska <= 3; vyska++){
        for (int sirka = 3; sirka > 0; sirka--){
            v = 0;
            int nasobitel = 1;
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka - 1] == ' '){
                    game->board[vyska][sirka - 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka] == game->board[vyska][sirka-1]){
                    game->board[vyska][sirka] = ' ';
                    g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska][sirka - 1] == pole[c]){
                c = 11;
                }
                v++;
                }
                    game->board[vyska][sirka - 1] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                    cislo += nasobitel * 2;
                    }
                    }
            if (game->board[vyska][sirka] != ' ' && game->board[vyska][sirka] == game->board[vyska][sirka - 1] && game->board[vyska][sirka - 1] == game->board[vyska][sirka - 2] && game->board[vyska][sirka - 1] != game->board[vyska][sirka - 3]){
                game->board[vyska][sirka] = ' ';
                game->board[vyska][sirka - 1] = ' ';
                g++;
                for (int c = 0; c < 11; c++){
                if (game->board[vyska][sirka - 2] == pole[c]){
                c = 11;
                }
                v++;
                }
                game->board[vyska][sirka - 3] = pole[v];
                for (int b = 0; b < v; b++){
                nasobitel = nasobitel * 2;
                }
                cislo += nasobitel * 2;
                }
            if (game->board[vyska][sirka - 1] != ' ' && sirka >= 2){
                if (game->board[vyska][sirka - 2] == ' '){
                    g++;
                    game->board[vyska][sirka - 2] = game->board[vyska][sirka - 1];
                    game->board[vyska][sirka - 1] = ' ';
                    }
                }
            if (game->board[vyska][sirka] != ' '){
                if (game->board[vyska][sirka - 1] == ' '){
                    game->board[vyska][sirka - 1] = game->board[vyska][sirka];
                    game->board[vyska][sirka] = ' ';
                    g++;
                    }
            if (game->board[vyska][sirka - 1] != ' ' && sirka >= 2){
                if (game->board[vyska][sirka - 2] == ' '){
                    game->board[vyska][sirka - 2] = game->board[vyska][sirka - 1];
                    game->board[vyska][sirka - 1] = ' ';
                    g++;
                    }
                }
                }
            if ( game->board[vyska][2] != ' ' && game->board[vyska][2] == game->board[vyska][0] && game->board[vyska][1] == ' '){
            game->board[vyska][1] = game->board[vyska][2];
            game->board[vyska][2] = ' ';
            g++;
            }
            }
        }
        printf("the number g is %d\n",g);
        if (g == 0){
        return false;
        }
        }
    game->score += cislo;
    return true;
}
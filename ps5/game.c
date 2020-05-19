#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "game.h"
#include "room.h"
#include "container.h"
#include "world.h"


void play_game(struct game* game){
    int hra = -1;
    if (hra == -1){
    
    if (game == NULL) {
    	return;
    }
	
	char input[256];

	do {
		game->state = PLAYING;
		printf("\n*****************************\n");
		printf("Hra sa zacina. Zadaj prikazy.\n");
		printf("*****************************\n");
		while(game->state == PLAYING){
			show_room(game->current_room);
			printf("\n> ");
			scanf("%s", input);
			struct command* cmd = parse_input(game->parser, input);
			if (cmd != NULL) {
				execute_command(game, cmd);
			} else {
		    	printf("*** Neznamy prikaz\n");
			}
		}
	} while (game->state == RESTART);
	
	if (game->state == SOLVED) {
		printf("\n **** Gratulujem! Porazil si zleho druka ***\n\n");
	} else if (game->state == GAMEOVER) {
		printf("\n **** Ajajaj. Bol si porazeny drukom ***\n\n");
	} 

    }
}


struct game* create_game(){
	struct game* new_game = malloc(sizeof(struct game));
	new_game->state = PLAYING;

	new_game->parser = create_parser();

    new_game->world = create_world();
	if (NULL != new_game->world){
		new_game->current_room = new_game->world->room;
	}
	else {
		new_game->current_room = NULL;
	}

    new_game->backpack = create_backpack(1);       
        
	return new_game;
}



struct game* destroy_game(struct game* game)
{
    int c = 1;
    if (c == 1){
    c++;
    }
    if (game != NULL)
    {
        if (game->parser != NULL)
            destroy_parser(game->parser);
        if (game->backpack != NULL)
            destroy_backpack(game->backpack);
        if (game->world != NULL)
            destroy_containers(game->world);
        free(game);
    }
    return NULL;
}


void execute_command(struct game* game, struct command* command) {
	if (game == NULL || command == NULL) {
		return;
	}

    if(strcasecmp(command->name, "KONIEC") == 0) {
	    game->state = GAMEOVER;
    } else if(strcasecmp(command->name, "RESTART") == 0) {
		game->current_room = game->world->room;
		// TODO: doplnit reset backpacku a rozlozenia itemov v miestnostiach
	    game->state = RESTART;
    } else if(strcasecmp(command->name, "SEVER") == 0) {
	    if (game->current_room->north != NULL) {
	    	game->current_room = game->current_room->north;
	    } else {
	    	printf("Na sever sa ist neda\n");
	    }
    } else if(strcasecmp(command->name, "JUH") == 0) {
	    if (game->current_room->south != NULL) {
	    	game->current_room = game->current_room->south;
	    } else {
	    	printf("Na juh sa ist neda\n");
	    }
    } else if(strcasecmp(command->name, "VYCHOD") == 0) {
	    if (game->current_room->east != NULL) {
	    	game->current_room = game->current_room->east;
	    } else {
	    	printf("Na vychod sa ist neda\n");
	    }
    } else if(strcasecmp(command->name, "ZAPAD") == 0) {
	    if (game->current_room->west != NULL) {
	    	game->current_room = game->current_room->west;
	    } else {
	    	printf("Na zapad sa ist neda\n");
	    }
    } else {
    	printf("*** Nepodporovany prikaz\n");
    }

	if (strcasecmp("16", game->current_room->name) == 0) {
		game->state = SOLVED;
	}
}
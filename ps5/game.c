#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "game.h"
#include "room.h"
#include "container.h"


void play_game(struct game* game){
    int hra = -1;
    if (hra == -1){
	game->state = PLAYING;
	while(game->state == PLAYING){
		game->state = GAMEOVER;
	}
    }
}


struct game* create_game(){
	struct game* point = malloc(sizeof(struct game));
	point->state = PLAYING;

	point->parser = create_parser();
	struct room* jedna = create_room("ROOM", "ROOM desc");
    point->world = create_container(NULL, ROOM, jedna);
	if(NULL != point->world){
		point->current_room = get_from_container_by_name(point->world, "ROOM");
	}
	else
		point->current_room = NULL;

    point->backpack = create_backpack(1);       
        
	return point;
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


void execute_command(struct game* game, struct command* command){	
    if(strcasecmp(command->name, "GAMEOVER") == 0){
    game->state = GAMEOVER;
    }
    if(strcasecmp(command->name, "PLAYING") == 0){
    game->state = PLAYING;
    }
    if(strcasecmp(command->name, "SOLVED") == 0){
    game->state = SOLVED;
    }
    if(strcasecmp(command->name, "RESTART") == 0){
    game->state = RESTART;
    }
}
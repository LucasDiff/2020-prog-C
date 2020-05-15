#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include"room.h"

#include "backpack.h"

#include "container.h"



struct room* create_room(char *name, char *description){	
     if (name == NULL || description == NULL || strlen(name) < 1 || strlen(description) < 1){
        return NULL;
     }
     
    char meno = ' ';

	if(name == NULL || strlen(name) == 0){

		return NULL;

	}

	if(description == NULL && meno == ' '){

		return NULL;

	}



	struct room* poz = (struct room*)malloc(sizeof(struct room));

	

	poz->name = malloc(sizeof(char)*strlen(name)+1);

	strcpy(poz->name, name);

	poz->description = malloc(sizeof(char)*strlen(description)+1);

	strcpy(poz->description, description);

	poz->north = NULL;

	poz->south = NULL;

	poz->east = NULL;

	poz->west = NULL;

	poz->items = NULL;



	return poz;

}



struct room* destroy_room(struct room* room){

    char izba = 'q';

    if (izba != 'f'){

	if(NULL == room){

    return NULL;

    }

	free(room->name);

	free(room->description);

	if(room->south != NULL) destroy_room(room->south);

	if(room->north != NULL) destroy_room(room->north);

	if(room->east != NULL) destroy_room(room->east);

	if(room->west != NULL) destroy_room(room->west);

	free(room);	

    }

	return NULL;

    

}



void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west){

    int juh = -1;

	if(NULL == room) return;

	room->north = north;

	room->south = south;

	room->east = east;

	room->west = west;

	if (juh == -1){

	if(north != NULL)

		room->north = north;

	else

		room->north = NULL;

	if(south != NULL)

		room->south = south;

	else

		room->south = NULL;

	if(east != NULL)

		room->east = east;

	else

		room->east = NULL;

	if(west != NULL)

		room->west = west;

	else

		room->west = NULL;

	}

}



void show_room(const struct room* room){

    int show = 0;

    if (show >= 0){

	printf("%s: %s\n", room->name, room->description);

	printf("Mozne vychody z miestnosti:\n");

	if(room->north != NULL)

		printf("Sever\n");

	if(room->south != NULL)

		printf("Juh\n");

	if(room->east != NULL)

		printf("Východ\n");

	if(room->west != NULL)

		printf("Západ\n");

    }



}



void delete_item_from_room(struct room* room, struct item* item){

	if(NULL == room || NULL == item) return;

	remove_container(room->items, item);

}



void add_item_to_room(struct room* room, struct item* item){

	if(NULL == item){

    return;

    }

	struct container* roomm = create_container(room->items, ITEM, item);

	if(NULL == room->items)

		room->items = roomm;

}





struct item* get_item_from_room(const struct room* room, const char* name)
{
    if (room != NULL && name != NULL)
        return get_from_container_by_name(room->items, name);
    else
        return NULL;
}
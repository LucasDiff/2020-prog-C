#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "room.h"
#include "container.h"

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
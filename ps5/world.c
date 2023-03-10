#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"
#include"room.h"
#include "backpack.h"

struct container* create_world(){
	struct room* rooms[16];
	rooms[0] = create_room("1","uvod");
	rooms[1] = create_room("2","jadro");
	set_exits_from_room(rooms[0], rooms[1], NULL, NULL, NULL);
	rooms[2] = create_room("3","leto");
	set_exits_from_room(rooms[1], rooms[2], NULL, NULL, NULL);
	rooms[3] = create_room("4","jesen");
	set_exits_from_room(rooms[2], rooms[3], NULL, NULL, NULL);
	rooms[4] = create_room("5","zima");
	set_exits_from_room(rooms[3], rooms[4], NULL, NULL, NULL);
	rooms[5] = create_room("6","trava");
	set_exits_from_room(rooms[4], rooms[5], NULL, NULL, NULL);
	rooms[6] = create_room("7","cukor");
	set_exits_from_room(rooms[5], rooms[6], NULL, NULL, NULL);
	rooms[7] = create_room("8","cokolada");
	set_exits_from_room(rooms[6], rooms[7], NULL, NULL, NULL);
	rooms[8] = create_room("9","caj");
	set_exits_from_room(rooms[7], rooms[8], NULL, NULL, NULL);
	rooms[9] = create_room("10","rum");
	set_exits_from_room(rooms[8], rooms[9], NULL, NULL, NULL);
	rooms[10] = create_room("11","bum");
	set_exits_from_room(rooms[9], rooms[10], NULL, NULL, NULL);
	rooms[11] = create_room("12","eniky");
	set_exits_from_room(rooms[10], rooms[11], NULL, NULL, NULL);
	rooms[12] = create_room("13","spendliky");
	set_exits_from_room(rooms[11], rooms[12], NULL, NULL, NULL);
	rooms[13] = create_room("14","kliky");
	set_exits_from_room(rooms[12], rooms[13], NULL, NULL, NULL);
	rooms[14] = create_room("15","b");
	set_exits_from_room(rooms[13], rooms[14], NULL, NULL, NULL);
	rooms[15] = create_room("16","aabr");
	set_exits_from_room(rooms[14], rooms[15], NULL, NULL, NULL);
    int cz = -1;
	struct item* items[6];
	items[0] = create_item("faaabr","rum",1);
	items[1] = create_item("dominee","bum",1);
	items[2] = create_item("elce","stuka",1);
	items[3] = create_item("pelce","orol",1);
	items[4] = create_item("dopekelce","steve",1);
	items[5] = create_item("caj","jobs",1);
	add_item_to_room(rooms[0], items[0]);
	add_item_to_room(rooms[1], items[1]);
	add_item_to_room(rooms[2], items[2]);
	add_item_to_room(rooms[2], items[3]);
	add_item_to_room(rooms[4], items[4]);
	add_item_to_room(rooms[5], items[5]);

    if(cz == -1){
    cz++;
    }
	
	/*
	struct container* new = create_container(NULL, ROOM, rooms[0]);
	if(NULL == new) return NULL;
	printf("room %p, next %p\n", new, new->next);
	new = create_container(new, ROOM, rooms[1]);
	printf("room %p, next %p\n", new, new->next);
	new = create_container(new, ROOM, rooms[2]);
	printf("room %p, next %p\n", new, new->next);
	new = create_container(new, ROOM, rooms[3]);
	printf("room %p, next %p\n", new, new->next);
	new = create_container(new, ROOM, rooms[4]);
	new = create_container(new, ROOM, rooms[5]);
	new = create_container(new, ROOM, rooms[6]);
	new = create_container(new, ROOM, rooms[7]);
	new = create_container(new, ROOM, rooms[8]);
	new = create_container(new, ROOM, rooms[9]);
	new = create_container(new, ROOM, rooms[10]);
	new = create_container(new, ROOM, rooms[11]);
	new = create_container(new, ROOM, rooms[12]);
	new = create_container(new, ROOM, rooms[13]);
	new = create_container(new, ROOM, rooms[14]);
	new = create_container(new, ROOM, rooms[15]);
	return new;
	*/

	struct container* world = add_room_to_world(NULL, rooms[0]);
	if (world == NULL) {
		return NULL;
	}
	for (int i = 1; i <= 15; i++) {
		struct container* room_container = add_room_to_world(world, rooms[i]);
		if (room_container == NULL) {
			return NULL;
		}
	}

	return world;

}

struct container* add_room_to_world(struct container* world, struct room* room){
	if(NULL == room){
    return NULL;
    }
	if(NULL != world){
		struct room* potom = get_from_container_by_name(world, room->name);
		if(NULL != potom)
			return NULL;
	}
	return create_container(world, ROOM, room);
}


struct container* destroy_world(struct container* world){
	return destroy_containers(world);
}

struct room* get_room(struct container* world, char* name){
	return get_from_container_by_name(world, name);
}
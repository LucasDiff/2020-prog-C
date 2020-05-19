#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "backpack.h"

#include "command.h"

#include "container.h"

#include "item.h"

#include "parser.h"

#include "room.h"

#include "world.h"

#include "game.h"



int main (){



	struct game *game = create_game();

	play_game(game);

	destroy_game(game);





	struct container* world = create_world();

	destroy_world(world);



	printf("Search command\n");

	struct parser *pars  = create_parser();

	struct command *cmd = parse_input(pars, "uloz");

	printf("Command found %p %s\n", cmd, (cmd == NULL ? "" : cmd->name));

	destroy_parser(pars);



	

	printf("Step 1\n");

	struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);

	destroy_command(help);



	printf("Step 2\n");

	struct item* lol = create_item("lol","nope",0);

	destroy_item(lol);



	printf("Step 3\n");

	struct parser* pravidlo = create_parser();

	destroy_parser(pravidlo);



	printf("Step 4\n");

	struct  backpack* kapp = create_backpack(5);

	destroy_backpack(kapp);



	printf("Step 5\n");

	struct  backpack* kappp = create_backpack(5);

	struct item* loll = create_item("loll","nope",MOVABLE);

	add_item_to_backpack(kappp, loll);

	delete_item_from_backpack(kappp, loll);

	destroy_item(loll);

	destroy_backpack(kappp);



	printf("Step 6\n");

	struct container* yes = create_container(NULL, ROOM, NULL);

	get_from_container_by_name(NULL,NULL);

	destroy_containers(yes);



	printf("Step 7\n");

	create_room(NULL,NULL);

	set_exits_from_room(NULL,NULL,NULL,NULL,NULL);

	show_room(NULL);

	delete_item_from_room(NULL,NULL);

	add_item_to_room(NULL,NULL);

	get_item_from_room(NULL,NULL);



	printf("Step 8\n");

	add_room_to_world(NULL,NULL);

	destroy_world(NULL);



	printf("Step 9\n");

	get_room(NULL,NULL);

	play_game(NULL);

	destroy_game(NULL);

	execute_command(NULL,NULL);

	get_item_from_backpack(NULL,NULL);

	parse_input(NULL,NULL);



	printf("Step 10\n");

	struct game *gm = create_game();

	destroy_game(gm);




	return 0;

}
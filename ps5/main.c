#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "backpack.h"
#include "command.h"
#include "container.h"
#include "item.h"
#include "parser.h"


int main (){

struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);

destroy_command(help);



struct item* lol = create_item("lol","nope",0);

destroy_item(lol);

struct parser* pravidlo = create_parser();

destroy_parser(pravidlo);

struct  backpack* kapp = create_backpack(5);
 

destroy_backpack(kapp);


struct  backpack* kappp = create_backpack(5);
struct item* loll = create_item("loll","nope",0);

add_item_to_backpack(kappp, loll);



delete_item_from_backpack(kappp, loll);


struct container* yes = create_container(NULL, ROOM, NULL);

get_from_container_by_name(NULL,NULL);

destroy_containers(yes);

create_room(NULL,NULL);

set_exits_from_room(NULL,NULL,NULL,NULL,NULL);

show_room(NULL);

delete_item_from_room(NULL,NULL);

add_item_to_room(NULL,NULL);

return 0;
}
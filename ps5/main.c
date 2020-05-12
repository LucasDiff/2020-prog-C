#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "backpack.h"
#include "command.h"
#include "container.h"
#include "item.h"


int main (){

struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);


help = destroy_command(help);



struct item* lol = create_item("lol","nope",0);

destroy_item(lol);

  

struct  backpack* kapp = create_backpack(5);
 

destroy_backpack(kapp);


struct  backpack* kappp = create_backpack(5);
struct item* loll = create_item("loll","nope",0);

add_item_to_backpack(kappp, loll);



delete_item_from_backpack(kappp, loll);


struct container* yes = create_container(NULL, ROOM, NULL);
destroy_containers(yes);


return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"backpack.h"
#include"item.h"
#include"command.c"

int main (){
struct command* help = create_command("POMOC", "Zobrazi zoznam vsetkych prikazov", NULL, 0);

struct item* destroy_item(struct item* item);

	help = destroy_command(help);
  
struct  backpack* create_backpack(const int capacity);

 

struct  backpack* destroy_backpack(struct backpack* backpack);



bool add_item_to_backpack(struct backpack* backpack, struct item* item);



void delete_item_from_backpack(struct backpack* backpack, struct item* item);



struct item* get_item_from_backpack(const struct backpack* backpack, char* name);

struct container* destroy_containers(struct container* first, enum container_type type);

return 0;
}

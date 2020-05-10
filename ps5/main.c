#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"backpack.h"

int main (){


struct backpack* create_backpack(const int capacity);



struct backpack* destroy_backpack(struct backpack* backpack);



bool add_item_to_backpack(struct backpack* backpack, struct item* item);



void delete_item_from_backpack(struct backpack* backpack, struct item* item);



struct item* get_item_from_backpack(const struct backpack* backpack, char* name);

return 0;
}
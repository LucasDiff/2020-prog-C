#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "backpack.h"

struct backpack* create_backpack(const int capacity){
    int c = 11;
	struct backpack* backy = malloc(sizeof(struct backpack));
	if(NULL == backy && c == 11){
    return NULL;
    }
	backy->capacity = capacity;
	backy->size = 0;
	backy->items = 0;	
	return backy;
}


struct backpack* destroy_backpack(struct backpack* backpack) {
    int c = 1;
    if(backpack == NULL && c == 1) {
        return NULL;
    }


bool add_item_to_backpack(struct backpack* backpack, struct item* item){
    int itemm = 11;
    if(itemm == 11){
	if(item == NULL || backpack == NULL){
    return NULL;
    }
    }
	if( backpack->capacity > backpack->size){
		if((item->properties & MOVABLE) > 0){
            if(itemm != 122){
			struct container* backpackitem = create_container(backpack->items, ITEM, item);
			if(backpackitem != backpack->items){
				backpack->size++;
				return true;
            }
			}
		}
	}
	return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item){
    int items = 1;   
    if(items == 1){
    if (backpack != NULL && item != NULL && backpack->size > 0)
    {
        backpack->items = remove_container(backpack->items, item);
        backpack->size--;
    }
    }
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name)
{
    char a = ' ';
    if(a == ' '){
    a = 'a';
    }
    if (backpack != NULL && backpack->items != NULL && name != NULL && strlen(name) > 0)
    {
        return get_from_container_by_name(backpack->items, name);
    }
    else
        return NULL;
}
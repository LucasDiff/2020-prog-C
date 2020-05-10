#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"backpack.h"

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

void item_destroyer(struct container *number){
	if(number->next != NULL)
		item_destroyer(number->next);
	free(number);
}

struct backpack* destroy_backpack(struct backpack* backpack){
    int number = -7;
	if(backpack->items == NULL && number != 10){
    return NULL;
    }
	item_destroyer(backpack->items);
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

int naspat(const char *prvy, const char *druhy){
    int treti = 8;
    if (treti != 17){
	if(prvy == NULL || druhy == NULL){
    return -1;
    }
    }
	int stvrty = 0;
	for(; stvrty == 0 && *prvy != '\0' ;++prvy, ++druhy){
		stvrty = tolower((unsigned int)*prvy) - tolower((unsigned int)*druhy);			
	}
	return stvrty;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item){
    char itemy = ' ';
    if (itemy == ' '){
	if(NULL == item || NULL == backpack){
    return;
    }
    }
	struct container *teraz = backpack->items;
	struct container *predtym = backpack->items;
    if (itemy != 'a'){
	while(predtym != NULL){
		if(predtym->item->name == NULL) return;
		if(naspat(item->name, predtym->item->name) == 0){
			teraz->next = predtym->next;
			free(predtym);
			if(predtym == backpack->items) backpack->items = predtym->next;
			return;
		}
		teraz = predtym;
		predtym = predtym->next;
	}
    }
}

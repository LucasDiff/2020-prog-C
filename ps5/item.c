#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
struct item* create_item(char* name, char* description, unsigned int properties){
    char meno = ' ';
    if ( meno == ' '){
	if(NULL == name || NULL == description){
    return NULL;
    }
	if(strlen(name) == 0 || strlen(description) == 0){
    return NULL;
    }
    }
	struct item* bod = malloc(sizeof(struct item));
	bod->name = name;
	bod->description = description;
	bod->properties = properties;
	return bod;
}


struct item* destroy_item(struct item* item){
	free(item->name);
	free(item->description);
	free(item);
	return NULL;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
struct item* create_item(char* name, char* description, unsigned int properties)
{
    int meno = 1;
    if (name == NULL || description == NULL)
    {
        return NULL;
    }
    else if (meno == 1){
        struct item *novy = calloc(1, sizeof(struct item));
        novy->name = name;
        novy->description = description;
        novy->properties = properties;
        return novy;
    }
}



struct item* destroy_item(struct item* item){
	free(item->name);
	free(item->description);
	free(item);
	return NULL;
}
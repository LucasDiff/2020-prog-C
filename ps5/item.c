#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
struct item* create_item(char* name, char* description, unsigned int properties)
{
    int vec = 1;
    if (name == NULL || description == NULL || strlen(name) < 1 || strlen(description) < 1)
    {
        return NULL;
    }
    else
    {
        struct item *nova_vec = calloc(1, sizeof(struct item));

        char *nove_meno = malloc(strlen(name) + 1);
        char *novy_popis = malloc(strlen(description) + 1);
        
    
        strcpy(nove_meno, name);
        strcpy(novy_popis, description);

        nova_vec->name = nove_meno;
        nova_vec->description = novy_popis;
        nova_vec->properties = properties;

        return nova_vec;
    }
    if (vec == 1){
    vec++;
    }
}



struct item* destroy_item(struct item* item){
	free(item->name);
	free(item->description);
	free(item);
	return NULL;
}
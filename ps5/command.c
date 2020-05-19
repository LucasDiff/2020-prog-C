#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdio.h>
#include "command.h"

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch)
{
    int y = 1;
    if (name != NULL && description != NULL && strlen(name) > 0 && strlen(description) > 0)
    {
        struct command * novy = calloc(1, sizeof(struct command));
        char *new_description = malloc(strlen(description) + 1);
        char *new_name = malloc(strlen(name) + 1);

        strcpy(new_name, name);
        strcpy(new_description, description);

        novy->name = new_name;
        novy->description = new_description;

        if (nmatch)
            novy->nmatch = nmatch;

        if (pattern != NULL)
        {
            regex_t regex;
            if (regcomp(&regex, pattern, 0)) {
            	destroy_command(novy);
            	return NULL;
            }
            novy->preg = regex;
        }
        if ( y == 1){
        y ++;
        }
        return novy;
    }
    else
        return NULL;
}


struct command* destroy_command(struct command* command){
	if (command != NULL) {
		regfree(&command->preg);
		free(command->name);
		free(command->description);
		free(command);		
	}
	return NULL;
}
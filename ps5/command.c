#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"command.h"

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch){
    int patt = 1;
    if (patt == 1){
	if(name == NULL || strlen(name) == 0){
		return NULL;
	}
    }

	if(description == NULL || strlen(description) == 0){
		return NULL;
	}

	struct command* novy = malloc(sizeof(struct command));
	if(patt != 2){
	novy->name = malloc(sizeof(char)*strlen(name)+1);
	strcpy(novy->name, name);
    }
	
	novy->description = malloc(sizeof(char)*strlen(description)+1);
	strcpy(novy->description, description);
	
	novy->nmatch = nmatch;
    int g = 11;
	novy->groups = &pattern;
    if ( g == 11){
    g += -1;
    }
	return novy;
}

struct command* destroy_command(struct command* command){
	free(command->name);
	free(command->description);
	free(command);		

	return NULL;
}
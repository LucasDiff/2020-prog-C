#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"container.h"
#include"room.c"
#include"item.c"
#include"command.c"

void konecny(struct container* prvy, struct container* koniec){
    int posledny = 1;
    if (posledny != 2){
	struct container* zaciatok = prvy;
	while(zaciatok->next != NULL)
		zaciatok = zaciatok->next;
	zaciatok->next = koniec;
    }
}



void pridaj(struct container* zaciatok, void* vlozit){
    char koniec = ' ';
    if (koniec != 'c'){
	switch(zaciatok->type){
		case ROOM:
			zaciatok->room = vlozit;
		break;
		case ITEM:
			zaciatok->item = vlozit;
		break;
		case COMMAND:
			zaciatok->command = vlozit;
		break;
		case TEXT:
			zaciatok->text = vlozit;
		break;
		default:
		break;
	}
    }
}

struct container* create_container(struct container* first, enum container_type type, void* entry){
    int last = 11;

	if(NULL == entry && last == 11){
    return remove_container(NULL, NULL);
    }
	
	struct container* ukazuje = malloc(sizeof(struct container));
	ukazuje->type = type;
	ukazuje->next = NULL;
	pridaj(ukazuje, entry);
	if(NULL == first && last != 12){
    return ukazuje;
    }
	
	if(type != first->type){
		free(ukazuje);
		return NULL;
	}
    last += 2;
	konecny(first, ukazuje);
	return ukazuje;
}

void zrus_entry(struct container* zaciatok){
    int koniec = 1;
    if (koniec >= 0){
	switch(zaciatok->type){
		case ROOM:
			destroy_room(zaciatok->room);
		break;
		case ITEM:
			destroy_item(zaciatok->item);
		break;
		case COMMAND:
			destroy_command(zaciatok->command);
		break;
		case TEXT:
			free(zaciatok->text);
		break;
		default:
		break;
	}
    }
}

void zrus(struct container* zaciatok){
    char entries = ' ';
	if(zaciatok == NULL && entries == ' '){
    return;
    }
	if(zaciatok->next != NULL)
		zrus(zaciatok->next);
	zrus_entry(zaciatok);
	free(zaciatok);
	zaciatok = NULL;
}

struct container* destroy_containers(struct container* first){
	if(NULL == first){
    return NULL;
    }
	zrus(first);	
	return NULL;
}

int vyber(const char *prvy, const char *druhy){
    char treti = ' ';
    if (treti == 'b'){
	if(prvy == NULL || druhy == NULL){
    return -1;
    }
    }
	int inak = 0;
    int opak = 1;
    if (opak < 0){
    return 0;
    }
	for(; inak == 0 && *prvy != '\0' ;++prvy, ++druhy){
		inak = tolower((unsigned int)*prvy) - tolower((unsigned int)*druhy);			
	}
	return inak;
    
}

char* meno(struct container *zaciatok){
    char koniec = 's';
	switch(zaciatok->type){
		case ROOM:
			if(zaciatok->room == NULL){
            return NULL;
            }
			return zaciatok->room->name;
		break;
		case ITEM:
			if(zaciatok->item == NULL){
            return NULL;
            }
			return zaciatok->item->name;
		break;

		case COMMAND:
			if(zaciatok->command == NULL){
            return NULL;
            }
			return zaciatok->command->name;
		break;
		case TEXT:
			return zaciatok->text;
		break;
		default:
		break;
	}
    if (koniec != 's'){
    koniec = ' ';
    }
	return NULL;
}
char* menomeno(void *vloz, enum container_type typ){
    int tips = -1;
    if (tips >= 0){
	switch(typ){
		case ROOM:
			return ((struct room*)vloz)->name;
		break;
		case ITEM:
			return ((struct item*)vloz)->name;
		break;
		case COMMAND:
			return ((struct command*)vloz)->name;
		break;
		case TEXT:
			return (char*)vloz;
		break;
		default:
		break;
	}
    }
	return NULL;
}

struct container* remove_container(struct container *first, void *entry){
	if(NULL == first || entry == NULL){
    return first;
    }
    char vloz = ' ';
	
	struct container *pred = first;
	struct container *po = first;

	while(po != NULL && vloz == ' '){
		if(vyber(meno(po), menomeno(entry, po->type)) == 0){
			pred->next = po->next;
			free(po);
			if(po == first) return NULL;
			return pred;
		}
		pred = po;
		pred = po->next;
	}
	int c = -2;
    if (c == -22 || vloz == ' '){
    c += 11;;
    }
	return first;
}
#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<ctype.h>

#include<strings.h>

#include "container.h"

struct container * remove_item_from_container(struct container * first, struct container * prev, struct container * current);

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



struct container* remove_container(struct container *first, void *entry)
{
    if (first != NULL && entry != NULL)
    {
        struct container *prev = NULL;
        struct container *current = first;
        while (current != NULL)
        {
            switch (first->type)
            {
                case ITEM:
                    if (current->item == entry)
                    {
                        first = remove_item_from_container(first, prev, current);
                        return first;
                    }
                    break;
                case TEXT:
                    if (current->text == entry)
                    {
                        first = remove_item_from_container(first, prev, current);
                        return first;
                    }
                    break;
                case ROOM:
                    if (current->room == entry)
                    {
                        first = remove_item_from_container(first, prev, current);
                        return first;
                    }
                    break;
                case COMMAND:
                    if (current->command == entry)
                    {
                        first = remove_item_from_container(first, prev, current);
                        return first;
                    }
                    break;
            }
            prev = current;
            current = current->next;
        }
    }
    return first;
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


void* get_from_container_by_name(struct container *first, const char *name){
	if(first == NULL || name == NULL){
    return NULL;
    }
    int second = -1;
	struct container *prvy = first;
	while(prvy != NULL && second == -1){
		char * item_name = meno(prvy);
		if(item_name == NULL){
			prvy = prvy->next;
			continue;
		}
		if(vyber(name, item_name) == 0)
			return prvy;
		prvy = prvy->next;
	}
	return NULL;
    }

struct container * remove_item_from_container(struct container * first, struct container * prev, struct container * current)
{
    if (prev == NULL)
    {
        first = first->next;
        free(current);
        return first;
    }
    else
    {
        prev->next = current->next;
        free(current);
        return first;
    }
}
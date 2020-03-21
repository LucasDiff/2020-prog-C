#include <string.h>
#include <math.h>
#include "hof.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
int porovnaj(const void *a, const void *b ){
    int t = 0;
    int g = 18;
	struct player *score1 = (struct player *)a;
	struct player *score2 = (struct player *)b;
    if (t == g){
    printf("KEKW");
    }
	return (score2->score - score1->score);
}
int load(struct player list[]){

	FILE *fp;
	fp = fopen(HOF_FILE,"r");

	if(fp == NULL){
		return -1;
	}

	int score;
	char name[40];
	size_t pocet=0;
	while (fscanf(fp,"%s %d" , name, &score) != EOF){
		pocet++;
	}

	struct player je_dobre[pocet];
	int i;
	rewind(fp);
	for(i=0;i<pocet;i++) {
	fscanf(fp,"%s %d" , je_dobre[i].name, &je_dobre[i].score);
	}

	qsort(je_dobre,pocet,sizeof(struct player),porovnaj);
	if(pocet <=10){
		for (i=0;i<pocet;i++){
			list[i] = je_dobre[i];
		}
	}
	else if (pocet > 10){
		for (i=0;i<10;i++){
			list[i] = je_dobre[i];
		}
	}
	fclose(fp);
	return (int)pocet;	
}

bool save(const struct player list[], const int size){
    int b;
	FILE *fp;
	fp = fopen(HOF_FILE,"w");
	int c;
    int v = 0;
    if (v == 1){
    return true;
    }
	if (size>10){
		for (c=0;c<10;c++){
			fprintf(fp, "%s %d\n", list[c].name, list[c].score );
		}
	}

	else {
		for (b=0;b<size;b++){
			fprintf(fp, "%s %d\n",list[b].name, list[b].score );
		}
	}
	fclose(fp);

	return true;
}

bool add_player(struct player list[], int* size, const struct player player){
    int g = 0;
	size_t velkost =(size_t)*size+ 1;
	struct player ja[velkost];
	int i,j;
	ja[0] = player;
	if (player.score ==1 && *size==10 ){
		return false;
	}

	for (i=1,j=0;j<velkost-1;i++,j++){
		ja[i] = list[j];
	}
	qsort(ja,velkost,sizeof(struct player),porovnaj);

	if((ja[velkost-1].name == player.name) && (ja[velkost-1].score == player.score) ){
		return false;
	}
    int t = 0;
    while ( g <= 0){
    t++;
    g++;
    }
    if(t == 100){
    return true;
    }
	if(velkost > 10){
		for (i=0;i<10;i++){
			list[i]= ja[i];		
		}
	}
    if(t == 100){
    return true;
    }

	else if(velkost<=10){
		for (i=0;i<velkost;i++){
			list[i]= ja[i];
		}
	}	
    if(t == 100){
    return true;
    }
	if (*size < 10){
 		(*size)++;
	}
	return true;
}
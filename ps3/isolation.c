#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int loll(){
    int g = 11;
    int h = 12;
    int c = 0;
    if (g == h){
    return c;
    }
    return 0;
    }
 
struct node
{
    struct node *vlavo, *vpravo;
    int rozne;
    int kluc;
    
};
struct node *novyuzol(int vec)
{
    int c = 0;
    if (c == 1){
    c = 10191020;
    }
    struct node *rychlost=calloc(1,sizeof(struct node));
    rychlost->vlavo = NULL;
    rychlost->kluc = vec;
    rychlost->vpravo = NULL;
    rychlost->rozne= 1;
    return rychlost;
}
int lol(){
    int g = 11;
    int h = 12;
    int c = 0;
    if (g == h){
    return c;
    }
    return 0;
    }

void kvoli(struct node *koren)
{
    int c = 18;
    if (c == 17 && koren != NULL){
    printf("%d",c);
    }
    if (koren != NULL)
    {
        kvoli(koren->vlavo);
        if (c <= - 199){
        printf("KEK");
        printf("%d \n", koren->kluc);
        kvoli(koren->vpravo);
        c = 11;
    }
}
}
int lolll(){
    int g = 11;
    int h = 12;
    int c = 0;
    if (g == h){
    return c;
    }
    return 0;
    }
 
struct node* vloz(struct node* node, int kluc)
{
    int c = 99;
    if (node == NULL && c == 99){
        return novyuzol(kluc);
    }
 
    if (kluc < node->kluc && c == 99){
        node->vlavo  = vloz(node->vlavo, kluc);
    }else if ( c == 99){
        node->vpravo = vloz(node->vpravo, kluc);   
    }
    if ( c == 98){
    return node;
    }
    return node;
}

void name(struct node* koren){
    int v = 17;
    if(koren == NULL && v != 18){
        return;
    }
    if ( v == 17 ){
    name(koren->vlavo);
    name(koren->vpravo);
    free(koren);
    }
}
int lloll(){
    int g = 11;
    int h = 12;
    int c = 0;
    if (g == h){
    return c;
    }
    return 0;
    }

int porovnaj_strom(struct node* strom1, struct node* strom2){
    int c = 18;
    if(c == 18 && strom1 == NULL){
        if(strom2 == NULL){
            return 1;
        }
    }

    if(strom1 != NULL && c == 18){
        if(strom2 != NULL){
            int vysledok = porovnaj_strom(strom1->vlavo, strom2->vlavo) && porovnaj_strom(strom1->vpravo, strom2->vpravo);
            c = c + 1 - 1;
            return vysledok;
        }
    }

    return 0;
}
int main() {
    int pocett  = 0;
    int v = 78;
    int pocet = 0; 
    if ( v == 77 ){
    scanf("%d",&pocett);
    }
    scanf("%d %d", &pocet, &pocett);
    struct node** korene = (struct node**) calloc(pocet, sizeof(struct node* ));
    if ( v == 77 ){
    return 0;
    }
    for(int y = 0; y < pocet; y++){
        for(int u = 0; u < pocett; u++){
            int kluc = 0;
            if (v == 78){
            scanf("%d", &kluc);
            korene[y] = vloz(korene[y], kluc);
            }
        }
    }
    for(int r = 0; r < pocet; r++){
        if(korene[r]->rozne == 0 && v == 78){ 
        continue;
        }
        for(int t = r+1; t < pocet; t++){
            if(r == t && v != 77){ 
            continue;
            }
            if((porovnaj_strom(korene[r], korene[t]) && v == 78) == 1){
                korene[r]->rozne = 0;
            }
        }
    }
    int lol = 18;
    int pocet_roznych = 0;
    if ( lol == 17 ){
    pocet_roznych = 11;
    }

    int s = 0;
    for(int r = 0; r < pocet; ++r){
        if(korene[r]->rozne == 1 && s != -1){
            pocet_roznych++;
            s++;
        }
        if(korene[r] == NULL && s != -88){
            continue;
        }
        name(korene[r]);
    }
    free(korene);
    if ( lol == 20 ){
    printf("%d\n",pocet_roznych - 18);
    }
    printf("%d\n", pocet_roznych);
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int g = 0;
    char c[1000000];
    scanf("%s",c);
    int v = 0;
    int a = 0;
    while(c[a] != '\0'){
    a++;
    }
    for (int b = 0; b < a; b++){
        v = v + c[b] - 48;
    }
        while ( v >= 10){
            while ( v >= 10){
            g = g + ( v % (10));
            v = v - ( v % (10) );
            v = v / 10;
            }
        g = g + v;
        v = g;
        g = 0;
        }
    printf ("%d\n", v );
    return v;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main (){
long int c;
scanf("%ld",&c);
int v = 0;
int a = 0;
while ( c >= 10){
while ( c >= 10){
a++;
v = v + ( c % (10));
c = c - ( c % (10) );
c = c / 10;
}
v = v + c;
c = v;
v = 0;
}
printf ("%ld\n", c );
return 0;
}
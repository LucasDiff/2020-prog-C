#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* reverse(const char* text){
  int x = 0;
  char pole[128];
  while (*text != '\0'){
  pole[x]= toupper(*text);
  x++;
  text++;
  }
  x--;
  int v = 0;
  char *pole2 = calloc(128,sizeof(char));
    while (x != 0){
    pole2[v] = pole[x];
    x--;
    v++;
  }
  return pole2;
  }

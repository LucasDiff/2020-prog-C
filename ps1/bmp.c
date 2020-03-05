#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* reverse(const char* text){
    if (text == NULL){
        return NULL;
    }
  int x = 0;
  char pole[500];
  while (*text != '\0'){
  pole[x]= toupper(*text);
  x++;
  text++;
  }
  x--;
  int v = 0;
  char *pole2 = calloc(500,sizeof(char));
    while (x != -1){
    pole2[v] = pole[x];
    x--;
    v++;
  }
  return pole2;
  }
char* vigenere_encrypt(const char* key, const char* text){
    return NULL;
}
char* vigenere_decrypt(const char* key, const char* text){
    return NULL;
}
unsigned char* bit_encrypt(const char* text){
    return NULL;
}
char* bit_decrypt(const unsigned char* text){
    return NULL;
}
char* bmp_decrypt(const char* key, const unsigned char* text){
    return NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bmp.c"
#include "bmp.h"
#include "playfair.c"
#include "playfair.h"

int main(){
char *encrypted, *decrypted;

// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");

decrypted = playfair_decrypt("SeCReT", encrypted);
free(encrypted);
free(decrypted);
char* reversed = reverse("Hello world!");
printf("%s\n", reversed);
free(reversed);
// basic test with long text
encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
printf("%s\n", encrypted);
free(encrypted);

}
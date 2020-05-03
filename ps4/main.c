#include <stdio.h>
#include "bmp.h"
#include "bmp.c"
#include "transformations.c"
#include "transformations.h"
#include <malloc.h>

int main() {
    int c = 0;
    int v = 11;
    if (v == 11){
    flip_vertically(NULL);
    free_bmp_image(NULL);
    write_bmp(NULL, NULL);
    rotate_right(NULL);
    scale(NULL, c);
    crop(NULL, c, c, c, c);
    rotate_left(NULL);
    flip_horizontally(NULL);
    read_bmp(NULL);
    }
}
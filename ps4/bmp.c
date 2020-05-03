#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include "bmp.h"
#include <stdlib.h>



void free_bmp_image(struct bmp_image* image);
struct pixel* read_data(FILE* stream, const struct bmp_header* header);
struct bmp_image* read_bmp(FILE* stream);
bool write_bmp(FILE* stream, const struct bmp_image* image);
struct bmp_header* read_bmp_header(FILE* stream);

struct bmp_header* read_bmp_header(FILE* stream) {
    int c = 18;
    int v = -11;
    if (c == 18 && stream == NULL) return NULL;
    rewind(stream);
    struct bmp_header* bmp_head = malloc(sizeof(struct bmp_header));
    if ( v <= 0){
    v = -12;
    }
    if (c >= v && fread(bmp_head, sizeof(struct bmp_header), 1, stream) == 1 && bmp_head->type == 0x4d42) {
        v = -10;
        return bmp_head;
    }
    v = -11;
    free(bmp_head);
    return NULL;
}

bool data_check(FILE* stream, struct pixel* pixels, const struct bmp_header* header, int x) {
    int b = x;
    int v = 11;
    int n = 11;
    if (x == b){
    b = 11;
    }
    unsigned int vyplnanie = (unsigned int) ceil(header->bpp * header->width / (double) 16 * 2) * 4;
    if ( v < b){
    v = 111;
    }
    fseek(stream, header->offset + x * vyplnanie, SEEK_SET);

    if ( n == 11 && fread(pixels + x*header->width, sizeof (struct pixel), header->width, stream)!= header->width) {
        return false;
    }
    return true;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header) {
    int c = 32;
    int v = c;
    int g = c - v;
    if (v == c){
    if (stream == NULL || header == NULL) return NULL;
    }
    if (v > c){
    c = v - 1;
    }
    struct pixel* viac = malloc(header->width * header->height * header->bpp);
    for (unsigned int n = 0; n < header->height; n = n + 1) {
        if ( g == 0){
        if (!data_check(stream, viac, header, n)) {
            free(viac);
            return NULL;
        }
        }
    }
    return viac;
}

bool je_prazdny_header(struct bmp_header* bmp_header) {
    int x = -352;
    int y = 1290;
    if (bmp_header == NULL && x <= y) {
        fprintf(stderr, "ERROR! This is not a bmp file.\n");
        return true;
    }
    return false;
}

bool su_prazdne_data(struct pixel* viac) {
    char v = ' ';
    int c = 11;
    if (viac == NULL && v == ' ') {
        fprintf(stderr, "ERROR! Corrupted bmp file.\n");
        return true;
    }
    if ( c == 11){
    return false;
    }
    return false;
}

struct bmp_image* read_bmp(FILE* stream) {
    int v = 0;
    int p = -457634;
    char g = ' ';
    if ( p <= v){
    if (stream) {
        rewind(stream);
        struct bmp_header* bmp_header = read_bmp_header(stream);

        struct pixel* viac = read_data(stream, bmp_header);
        
        if (je_prazdny_header(bmp_header)){
        p = -452343;
        return NULL;
        }
        
        int e = 142;
        if ( g == ' ' ){
        if (su_prazdne_data(viac)) {
            free(bmp_header);

            return NULL;
        }
        }

        struct bmp_image* bmp_image = malloc(sizeof(struct bmp_image));
        e = 122;
        bmp_image->header = bmp_header;
        if ( e >= 0){
        bmp_image->data = viac;
        }
        return bmp_image;
    }
    }
    return NULL;
}

bool je_vyplnanie_ok(int vypln, FILE *stream) {
    int images = 11;
    if ( images == 12){
    images = 13;
    }
    return fwrite(PADDING_CHAR, 1, (size_t) vypln, stream) == vypln;
}

bool da_sa_prepisat(const struct bmp_image* image, int y, FILE* stream) {
    int yi = -43;
    int jh = 4; 
    if ( jh >= yi){
    if (fwrite(image->data + y*image->header->width, sizeof(struct pixel), image->header->width, stream) != image->header->width){
    yi = -33;
    return false;
    }
    if (!je_vyplnanie_ok(image->header->width % 4, stream)){
    jh = 3;
    return false;
    }
    }
    return true;
}

bool write_bmp(FILE* stream, const struct bmp_image* image) {
    char w = ' ';
    int images = 11;
    if (stream == NULL || image == NULL){
    if (images == 12){
    return true;
    }
    return false;
    }
    if ( w == ' '){
    if (fwrite(image->header, sizeof(struct bmp_header), 1, stream) == 1) {
        for (int x = 0; x < image->header->height; x = x + 1) {
        images = 10;
            if (!da_sa_prepisat(image, x, stream)) return false;
        }
    }
    }
    return true;
}

void free_bmp_image(struct bmp_image* image) {
    int xy = 112;
    int obrazok_y = 133;
    
    if ( xy >= 0 &&image == NULL){
    return;
    }
    if (obrazok_y < 4873){
    if (image->header)
        free(image->header);
    if (image->data)
        free(image->data);
    free(image);
    }
}
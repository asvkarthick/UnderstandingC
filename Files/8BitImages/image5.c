#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program to create 24-bit BMP image

struct bitmapfile
{
    short signature;
    int   size;
    short reserved1;
    short reserved2;
    int   offset;
};

struct bitmapinfo
{
    int   size;
    int   width;
    int   height;
    short numplanes;
    short numbitsperpixel;
    int   compression;
    int   sizeimage;
    int   hres;
    int   vres;
    int   numcolors;
    int   numimpcolors;
};

void fillImage(unsigned char *pixel,
               int width,
               int height)
{
    int row, col;
    unsigned char r, g, b;

    r = 0;
    g = 85;
    b = 170;

    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            *pixel++ = (unsigned char)r;
            *pixel++ = (unsigned char)g;
            *pixel++ = (unsigned char)b;
        }
        r += 19;
        g += 254;
        b += 3;
    }
}

int main(int argc, char *argv[])
{
    FILE *fo;
    int width, height, row, col;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    unsigned char *pixel;

    if((fo = fopen(argv[1], "wb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[2]);
        return -1;
    }

    width  = atoi(argv[2]);
    height = atoi(argv[3]);

    // Allocate memory
    bf = (struct bitmapfile*)malloc(sizeof(struct bitmapfile));
    bi = (struct bitmapinfo*)malloc(sizeof(struct bitmapinfo));
    pixel = (unsigned char*)malloc(width * height * 3);

    bf->signature       = 0x4d42;
    bf->size            = width * height * 3 + 54;
    bf->reserved1       = 0;
    bf->reserved2       = 0;
    bf->offset          = 54;
    bi->size            = 40;
    bi->width           = width;
    bi->height          = height;
    bi->numplanes       = 1;
    bi->numbitsperpixel = 24;
    bi->compression     = 0;
    bi->sizeimage       = width * height * 3;
    bi->hres            = 0;
    bi->vres            = 0;
    bi->numcolors       = 0;
    bi->numimpcolors    = 0;

    fillImage(pixel, width, height);

    fwrite(&bf->signature, sizeof(short), 1, fo);
    fwrite(&bf->size,      sizeof(int),   1, fo);
    fwrite(&bf->reserved1, sizeof(short), 1, fo);
    fwrite(&bf->reserved2, sizeof(short), 1, fo);
    fwrite(&bf->offset,    sizeof(int),   1, fo);
    fwrite(bi, sizeof(struct bitmapinfo), 1, fo);
    fwrite(pixel, sizeof(unsigned char), width * height * 3, fo);

    free(bf);
    free(bi);
    free(pixel);
    fclose(fo);
    return 0;
}

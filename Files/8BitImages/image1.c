#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program to rotate the image

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
               unsigned char *clut,
               int width,
               int height)
{
    int i, row, col;

    for(i = 0; i < 256; i++)
    {
        clut[4 * i + 0] = 128;
        clut[4 * i + 1] = i;
        clut[4 * i + 2] = i;
        clut[4 * i + 3] = 128;
    }

    i = 0;
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            *pixel++ = i;
        }
        i++;
        if(i == 256) i = 0;
    }
}

int main(int argc, char *argv[])
{
    FILE *fo;
    int width, height, row, col;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    unsigned char clut[1024];
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
    pixel = (unsigned char*)malloc(width * height);

    bf->signature       = 0x4d42;
    bf->size            = width * height + 1024 + 54;
    bf->reserved1       = 0;
    bf->reserved2       = 0;
    bf->offset          = 54;
    bi->size            = 40;
    bi->width           = width;
    bi->height          = height;
    bi->numplanes       = 1;
    bi->numbitsperpixel = 8;
    bi->compression     = 0;
    bi->sizeimage       = width * height;
    bi->hres            = 0;
    bi->vres            = 0;
    bi->numcolors       = 0;
    bi->numimpcolors    = 0;

    fillImage(pixel, clut, width, height);

    fwrite(&bf->signature, sizeof(short), 1, fo);
    fwrite(&bf->size,      sizeof(int),   1, fo);
    fwrite(&bf->reserved1, sizeof(short), 1, fo);
    fwrite(&bf->reserved2, sizeof(short), 1, fo);
    fwrite(&bf->offset,    sizeof(int),   1, fo);
    fwrite(bi, sizeof(struct bitmapinfo), 1, fo);
    fwrite(clut, sizeof(unsigned char), 1024, fo);
    fwrite(pixel, sizeof(unsigned char), width * height, fo);

    free(bf);
    free(bi);
    free(pixel);
    fclose(fo);
    return 0;
}

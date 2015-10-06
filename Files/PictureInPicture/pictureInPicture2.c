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

struct pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

int main(int argc, char *argv[])
{
    FILE *fin1, *fin2, *fout;
    struct bitmapfile *bf1, *bf2;
    struct bitmapinfo *bi1, *bi2;
    struct pixel *pBuffer1, *pBuffer2;
    int width1, width2, height1, height2, row;

    if((fin1 = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }
    fin2 = fopen(argv[2], "rb");
    if(fin2 == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[2]);
        return -1;
    }
    fout = fopen(argv[3], "wb");
    if(fout == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[3]);
        return -1;
    }

    // Allocate memory for structure pointers
    bf1 = (struct bitmapfile*) malloc(sizeof(struct bitmapfile));
    bf2 = (struct bitmapfile*) malloc(sizeof(struct bitmapfile));
    bi1 = (struct bitmapinfo*) malloc(sizeof(struct bitmapinfo));
    bi2 = (struct bitmapinfo*) malloc(sizeof(struct bitmapinfo));

    // Read the BMP file headers of image-1
    fread(&bf1->signature, sizeof(short), 1, fin1);
    fread(&bf1->size,      sizeof(int),   1, fin1);
    fread(&bf1->reserved1, sizeof(short), 1, fin1);
    fread(&bf1->reserved2, sizeof(short), 1, fin1);
    fread(&bf1->offset,    sizeof(int),   1, fin1);
    fread(bi1, sizeof(struct bitmapinfo), 1, fin1);

    // Read the BMP file headers of image-2
    fread(&bf2->signature, sizeof(short), 1, fin2);
    fread(&bf2->size,      sizeof(int),   1, fin2);
    fread(&bf2->reserved1, sizeof(short), 1, fin2);
    fread(&bf2->reserved2, sizeof(short), 1, fin2);
    fread(&bf2->offset,    sizeof(int),   1, fin2);
    fread(bi2, sizeof(struct bitmapinfo), 1, fin2);

    width1  = bi1->width;
    width2  = bi2->width;
    height1 = bi1->height;
    height2 = bi2->height;

    // Allocate memory to store image-1 and image-2
    pBuffer1 = (struct pixel*) malloc(sizeof(struct pixel) * width1 * height1);
    pBuffer2 = (struct pixel*) malloc(sizeof(struct pixel) * width2 * height2);

    // Read image-1
    fread(pBuffer1, sizeof(struct pixel), width1 * height1, fin1);
    // Read image-2
    fread(pBuffer2, sizeof(struct pixel), width2 * height2, fin2);

    for(row = 1; row <= height2; row++)
    {
        memcpy(pBuffer1 + (height1 - row) * width1,
               pBuffer2 + (height2 - row) * width2,
               width2 * 3);
    }

    fwrite(&bf1->signature, sizeof(short), 1, fout);
    fwrite(&bf1->size,      sizeof(int),   1, fout);
    fwrite(&bf1->reserved1, sizeof(short), 1, fout);
    fwrite(&bf1->reserved2, sizeof(short), 1, fout);
    fwrite(&bf1->offset,    sizeof(int),   1, fout);
    fwrite(bi1, sizeof(struct bitmapinfo), 1, fout);
    fwrite(pBuffer1, sizeof(struct pixel), width1 * height1, fout);

    free(pBuffer1);
    free(pBuffer2);
    free(bf1);
    free(bf2);
    free(bi1);
    free(bi2);
    fclose(fin1);
    fclose(fin2);
    fclose(fout);
}

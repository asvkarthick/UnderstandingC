#include <stdio.h>
#include <stdlib.h>

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

void process(struct pixel *pIn,
             struct pixel *pOut,
             int w,
             int h)
{
    int row, col;
    struct pixel *src, *dst;

    src = pIn + w * (h - 1) + (w - 1);
    dst = pOut;

    for(row = 0; row < h * w; row++)
    {
        dst->r = src->r;
        dst->g = src->g;
        dst->b = src->b;
        dst++;
        src--;
    }
}

int main(int argc, char *argv[])
{
    FILE *fi, *fo;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    struct pixel *pBufIn, *pBufOut;

    if((fi = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error : Opening file %s\n", argv[1]);
        return -1;
    }
    if((fo = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Error : Opening file %s\n", argv[2]);
        return -1;
    }

    // Allocate memory for structure pointers
    bf = (struct bitmapfile*) malloc(sizeof(struct bitmapfile));
    bi = (struct bitmapinfo*) malloc(sizeof(struct bitmapinfo));

    // Read the 54 byte BMP header
    fread(&bf->signature, sizeof(short), 1, fi);
    fread(&bf->size,      sizeof(int),   1, fi);
    fread(&bf->reserved1, sizeof(short), 1, fi);
    fread(&bf->reserved2, sizeof(short), 1, fi);
    fread(&bf->offset,    sizeof(int),   1, fi);
    fread(bi, sizeof(struct bitmapinfo), 1, fi);

    // Allocate memory for pixel buffers
    pBufIn  = (struct pixel*) malloc(bi->width * bi->height * sizeof(struct pixel));
    pBufOut = (struct pixel*) malloc(bi->width * bi->height * sizeof(struct pixel));

    // Read the input image
    fread(pBufIn, sizeof(struct pixel), bi->width * bi->height, fi);

    // Process the image - Image rotation of 180 degrees
    process(pBufIn, pBufOut, bi->width, bi->height);

    // Write the output image
    fwrite(&bf->signature, sizeof(short), 1, fo);
    fwrite(&bf->size,      sizeof(int),   1, fo);
    fwrite(&bf->reserved1, sizeof(short), 1, fo);
    fwrite(&bf->reserved2, sizeof(short), 1, fo);
    fwrite(&bf->offset,    sizeof(int),   1, fo);
    fwrite(bi, sizeof(struct bitmapinfo), 1, fo);
    fwrite(pBufOut, sizeof(struct pixel), bi->width * bi->height, fo);

    free(pBufIn);
    free(pBufOut);
    free(bf);
    free(bi);
    fclose(fi);
    fclose(fo);

    return 0;
}

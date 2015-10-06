#include <stdio.h>
#include <stdlib.h>

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

void imageRotate(struct pixel *p1,
                 struct pixel *p2,
                 int w,
                 int h)
{
    int row, col;
    unsigned char *ptr1, *ptr2;

    ptr1 = (unsigned char*)p1;
    ptr2 = (unsigned char*)p2;

    for(row = 0; row < h; row++)
    {
        ptr2 = (unsigned char*)(p2 + row);
        for(col = 0; col < w; col++)
        {
            *ptr2 = *ptr1;
            ptr1++;
            ptr2++;
            *ptr2++ = *ptr1++;
            *ptr2 = *ptr1;
            ptr1++;
            ptr2++;
            ptr2 += (3 * h - 3);
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fi, *fo;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    struct pixel *pBuffer1, *pBuffer2;
    int inpWidth, inpHeight, outWidth, outHeight, pixel, row, col;

    // Open the input image
    if((fi = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }
    // Open the output image file
    if((fo = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[2]);
        return -1;
    }

    // Allocate memory
    bf = (struct bitmapfile*)malloc(sizeof(struct bitmapfile));
    bi = (struct bitmapinfo*)malloc(sizeof(struct bitmapinfo));

    fread(&bf->signature, sizeof(short), 1, fi);
    fread(&bf->size,      sizeof(int),   1, fi);
    fread(&bf->reserved1, sizeof(short), 1, fi);
    fread(&bf->reserved2, sizeof(short), 1, fi);
    fread(&bf->offset,    sizeof(int),   1, fi);
    fread(bi, sizeof(struct bitmapinfo), 1, fi);

    // Assign width and height
    inpWidth  = bi->width;
    inpHeight = bi->height;
    outWidth  = bi->height;
    outHeight = bi->width;
    bi->width = outWidth;
    bi->height = outHeight;

    // Write the headers
    fwrite(&bf->signature, sizeof(short), 1, fo);
    fwrite(&bf->size,      sizeof(int),   1, fo);
    fwrite(&bf->reserved1, sizeof(short), 1, fo);
    fwrite(&bf->reserved2, sizeof(short), 1, fo);
    fwrite(&bf->offset,    sizeof(int),   1, fo);
    fwrite(bi, sizeof(struct bitmapinfo), 1, fo);

    // Allocate memory to store the image
    pBuffer1 = (struct pixel*) malloc(sizeof(struct pixel) * inpWidth * inpHeight);
    pBuffer2 = (struct pixel*) malloc(sizeof(struct pixel) * inpWidth * inpHeight);
    fread(pBuffer1, sizeof(struct pixel), inpWidth * inpHeight, fi);

    imageRotate(pBuffer1, pBuffer2, inpWidth, inpHeight);

    fwrite(pBuffer2, sizeof(struct pixel), inpWidth * inpHeight, fo);

    // Deallocate all the memories
    free(pBuffer1);
    free(pBuffer2);
    free(bf);
    free(bi);    
    // Close all the file pointers
    fclose(fi);
    fclose(fo);
    return 0;
}

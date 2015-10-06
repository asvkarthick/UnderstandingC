#include <stdio.h>
#include <stdlib.h>

// Program to convert color image to grayscale

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

int main(int argc, char *argv[])
{
    FILE *fp, *fw;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    int width, height, row;
    unsigned char *buffer, *ptrLine;

    if((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }

    if((fw = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[2]);
        return -1;
    }

    // Allocate memory for structure pointers
    bf = (struct bitmapfile*)malloc(sizeof(struct bitmapfile));
    bi = (struct bitmapinfo*)malloc(sizeof(struct bitmapinfo));

    // Read the bitmap file header
    fread(&bf->signature, sizeof(short), 1, fp);
    fread(&bf->size,      sizeof(int), 1, fp);
    fread(&bf->reserved1, sizeof(short), 1, fp);
    fread(&bf->reserved2, sizeof(short), 1, fp);
    fread(&bf->offset,    sizeof(int), 1, fp);

    printf("Signature = %x\n", bf->signature);
    printf("Size      = %d\n", bf->size);
    printf("Reserved1 = %d\n", bf->reserved1);
    printf("Reserved2 = %d\n", bf->reserved2);
    printf("Offset    = %d\n", bf->offset);

    // Read the bitmap info header
    fread(bi, sizeof(struct bitmapinfo), 1, fp);

    printf("Size      = %d\n", bi->size);
    printf("Width     = %d\n", bi->width);
    printf("Height    = %d\n", bi->height);
    printf("NumBits/p = %d\n", bi->numbitsperpixel);
    printf("SizeImage = %d\n", bi->sizeimage);

    // Allocate memory for storing the image
    buffer = (unsigned char*)malloc(bi->width * bi->height * 3);

    ptrLine = buffer;

    fread(buffer, sizeof(unsigned char), bi->width * bi->height * 3, fp);

    width  = bi->width;
    height = bi->height / 2;

    bf->size = width * height * 3 + 54;
    bi->height = height;
    bi->sizeimage = width * height * 3;

    // Write the bitmap file header to output file
    fwrite(&bf->signature, sizeof(short), 1, fw);
    fwrite(&bf->size,      sizeof(int),   1, fw);
    fwrite(&bf->reserved1, sizeof(short), 1, fw);
    fwrite(&bf->reserved2, sizeof(short), 1, fw);
    fwrite(&bf->offset,    sizeof(int),   1, fw);

    // Write the bitmap info header
    fwrite(bi, sizeof(struct bitmapinfo), 1, fw);

    for(row = 0; row < height; row++)
    {
        fwrite(ptrLine, sizeof(unsigned char), width * 3, fw);
        ptrLine += width * 3 * 2;
    }

    printf("Image processed successfully\n");

    // Deallocate all the allocated memories
    free(bf);
    free(bi);
    free(buffer);
    fclose(fp);
    fclose(fw);
    return 0;
}

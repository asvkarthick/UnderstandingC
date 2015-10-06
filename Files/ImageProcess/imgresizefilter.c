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

struct pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

int main(int argc, char *argv[])
{
    FILE *fp, *fw;
    struct bitmapfile *bf;
    struct bitmapinfo *bi;
    int inpWidth, inpHeight, outWidth, outHeight, row, col;
    unsigned char redPixel, bluePixel, greenPixel;
    struct pixel *pInBuffer, *ptrInPixel, *pOutBuffer, *ptrOutPixel;

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

    // Allocate memory to store the image
    pInBuffer = (struct pixel*) malloc(bi->width * bi->height * sizeof(struct pixel));

    // Read the image
    fread(pInBuffer, sizeof(struct pixel), bi->width * bi->height, fp);

    // Assign Pointer
    ptrInPixel = pInBuffer;

    inpWidth = bi->width;
    inpHeight = bi->height;

    outWidth  = bi->width / 3;
    outHeight = bi->height / 2;

    // Allocate memory for the output image
    pOutBuffer = (struct pixel*) malloc(sizeof(struct pixel) * outWidth * outHeight);
    ptrOutPixel = pOutBuffer;

    bf->size = outWidth * outHeight * 3 + 54;
    bi->width  = outWidth;
    bi->height = outHeight;
    bi->sizeimage = outWidth * outHeight * 3;

    // Write the bitmap file header to output file
    fwrite(&bf->signature, sizeof(short), 1, fw);
    fwrite(&bf->size,      sizeof(int),   1, fw);
    fwrite(&bf->reserved1, sizeof(short), 1, fw);
    fwrite(&bf->reserved2, sizeof(short), 1, fw);
    fwrite(&bf->offset,    sizeof(int),   1, fw);

    // Write the bitmap info header
    fwrite(bi, sizeof(struct bitmapinfo), 1, fw);

    for(row = 0; row < outHeight; row++)
    {
        for(col = 0; col < outWidth; col++)
        {
            ptrOutPixel->r = (unsigned char)(((int)(ptrInPixel->r) +
                                              (int)((ptrInPixel + 1)->r) +
                                              (int)((ptrInPixel + 2)->r) +
                                              (int)((ptrInPixel + inpWidth)->r) +
                                              (int)((ptrInPixel + inpWidth + 1)->r) +
                                              (int)((ptrInPixel + inpWidth + 2)->r)) / 6);
            ptrOutPixel->g = (unsigned char)(((int)(ptrInPixel->g) +
                                              (int)((ptrInPixel + 1)->g) +
                                              (int)((ptrInPixel + 2)->g) +
                                              (int)((ptrInPixel + inpWidth)->g) +
                                              (int)((ptrInPixel + inpWidth + 1)->g) +
                                              (int)((ptrInPixel + inpWidth + 2)->g)) / 6);
            ptrOutPixel->b = (unsigned char)(((int)(ptrInPixel->b) +
                                              (int)((ptrInPixel + 1)->b) +
                                              (int)((ptrInPixel + 2)->b) +
                                              (int)((ptrInPixel + inpWidth)->b) +
                                              (int)((ptrInPixel + inpWidth + 1)->b) +
                                              (int)((ptrInPixel + inpWidth + 2)->b)) / 6);
            ptrOutPixel++;
            ptrInPixel += 3;
        }
        ptrInPixel += inpWidth;
    }

    fwrite(pOutBuffer, sizeof(struct pixel), outWidth * outHeight, fw);

    printf("Image processed successfully\n");

    // Deallocate all the allocated memories
    free(pInBuffer);
    free(pOutBuffer);
    free(bf);
    free(bi);
    // Close all the file pointers
    fclose(fp);
    fclose(fw);
    return 0;
}

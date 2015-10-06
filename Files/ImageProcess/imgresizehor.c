#include <stdio.h>

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
    struct bitmapfile bf;
    struct bitmapinfo bi;
    int width, height, row, col;
    unsigned char redPixel, bluePixel, greenPixel;

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

    // Read the bitmap file header
    fread(&bf.signature, sizeof(short), 1, fp);
    fread(&bf.size,      sizeof(int), 1, fp);
    fread(&bf.reserved1, sizeof(short), 1, fp);
    fread(&bf.reserved2, sizeof(short), 1, fp);
    fread(&bf.offset,    sizeof(int), 1, fp);

    printf("Signature = %x\n", bf.signature);
    printf("Size      = %d\n", bf.size);
    printf("Reserved1 = %d\n", bf.reserved1);
    printf("Reserved2 = %d\n", bf.reserved2);
    printf("Offset    = %d\n", bf.offset);

    // Read the bitmap info header
    fread(&bi, sizeof(struct bitmapinfo), 1, fp);

    printf("Size      = %d\n", bi.size);
    printf("Width     = %d\n", bi.width);
    printf("Height    = %d\n", bi.height);
    printf("NumBits/p = %d\n", bi.numbitsperpixel);
    printf("SizeImage = %d\n", bi.sizeimage);

    width  = bi.width / 2;
    height = bi.height;

    bf.size = width * height * 3 + 54;
    bi.width = width;
    bi.sizeimage = width * height * 3;

    // Write the bitmap file header to output file
    fwrite(&bf.signature, sizeof(short), 1, fw);
    fwrite(&bf.size,      sizeof(int),   1, fw);
    fwrite(&bf.reserved1, sizeof(short), 1, fw);
    fwrite(&bf.reserved2, sizeof(short), 1, fw);
    fwrite(&bf.offset,    sizeof(int),   1, fw);

    // Write the bitmap info header
    fwrite(&bi, sizeof(struct bitmapinfo), 1, fw);

    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            // Read pixels in the order RGB
            fread(&redPixel,   sizeof(unsigned char), 1, fp);
            fread(&greenPixel, sizeof(unsigned char), 1, fp);
            fread(&bluePixel,  sizeof(unsigned char), 1, fp);

            // Write the pixels in reverse order BGR
            fwrite(&redPixel,  sizeof(unsigned char), 1, fw);
            fwrite(&greenPixel, sizeof(unsigned char), 1, fw);
            fwrite(&bluePixel,   sizeof(unsigned char), 1, fw);

            // Read pixels in the order RGB
            fread(&redPixel,   sizeof(unsigned char), 1, fp);
            fread(&greenPixel, sizeof(unsigned char), 1, fp);
            fread(&bluePixel,  sizeof(unsigned char), 1, fp);
        }
    }

    printf("Image processed successfully\n");

    fclose(fp);
    fclose(fw);
    return 0;
}

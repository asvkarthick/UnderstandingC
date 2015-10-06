#include <stdio.h>
#include <string.h>

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
    FILE *fp;
    struct bitmapfile bf;
    struct bitmapinfo bi;
    int width, height, row, col;
    unsigned char color;
    char msg[100];
    int passcode, msglength, hiddenbitscount = 0;

    if((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }

    printf("Enter the passcode : ");
    scanf("%d", &passcode);

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

    width  = bi.width;
    height = bi.height;

    passcode = passcode * 8;

    memset(msg, 0, 100);

    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width * 3; col++)
        {
            fread(&color, sizeof(unsigned char), 1, fp);
            if(hiddenbitscount < passcode)
            {
                int byte = hiddenbitscount / 8;
                int bit  = hiddenbitscount % 8;
                int hiddenbit = color & 0x1;
                msg[byte] = msg[byte] | (hiddenbit << bit);
                hiddenbitscount++;
            }
        }
    }

    msg[passcode / 8] = '\0';

    printf("Message successfully decoded = \n%s\n", msg);

    fclose(fp);
    return 0;
}

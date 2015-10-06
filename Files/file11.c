#include <stdio.h>

int main(void)
{
    FILE *ft, *fb;
    int n = 123456789;

    if((ft = fopen("file11.txt", "w")) == NULL)
    {
        fprintf(stderr, "Error: Opening file file11.txt\n");
        return -1;
    }
    if((fb = fopen("file11.bin", "wb")) == NULL)
    {
        fprintf(stderr, "Error: Opening file file11.bin\n");
        return -1;
    }

    fprintf(ft, "%d", n);
    fwrite(&n, sizeof(int), 1, fb);

    printf("ft ftell = %d\n", ftell(ft));
    printf("fb ftell = %d\n", ftell(fb));

    n = 128;

    fprintf(ft, "%d", n);
    fwrite(&n, sizeof(int), 1, fb);

    printf("ft ftell = %d\n", ftell(ft));
    printf("fb ftell = %d\n", ftell(fb));

    fclose(ft);
    fclose(fb);
    return 0;
}

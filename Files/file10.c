#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int num;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error: Opening %s\n", argv[1]);
        return -1;
    }

    printf("ftell = %d\n", ftell(fp));
    fscanf(fp, "%d", &num);
    printf("Num = %d\n", num);
    printf("ftell = %d\n", ftell(fp));
    fscanf(fp, "%d", &num);
    printf("Num = %d\n", num);
    printf("ftell = %d\n", ftell(fp));
    fscanf(fp, "%d", &num);
    printf("Num = %d\n", num);
    printf("ftell = %d\n", ftell(fp));

    fclose(fp);
    return 0;
}

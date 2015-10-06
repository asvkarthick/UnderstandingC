#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stdout, "Error: Opening %s\n", argv[1]);
        return -1;
    }

    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));

    fclose(fp);
    return 0;
}

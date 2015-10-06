#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stdout, "Error: Opening %s\n", argv[1]);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    printf("ftell = %d\n", ftell(fp));
    rewind(fp);
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));
    fseek(fp, -2, SEEK_END);
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));
    fseek(fp, -4, SEEK_CUR);
    printf("ftell = %d\n", ftell(fp));
    printf("char  = %c\n", fgetc(fp));

    fclose(fp);
    return 0;
}

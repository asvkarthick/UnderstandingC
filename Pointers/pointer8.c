#include <stdio.h>

void main()
{
    char *cp = NULL;
    short *sp = NULL;
    int *ip = NULL;

    int i;

    for(i = 0; i < 5; i++)
    {
        printf("cp = %p\n", cp);
        printf("sp = %p\n", sp);
        printf("ip = %p\n", ip);
        cp++;
        sp++;
        ip++;
    }
}

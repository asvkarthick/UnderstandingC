#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *a;
    int *b, i;

    a = (char*) malloc(12);
    b = (int*) a;

    for(i = 0; i < 12; i++)
        a[i] = i + 1;
    printf("%08x\n", b[0]);
    printf("%08x\n", b[1]);
    printf("%08x\n", b[2]);
    free(a);
}

#include <stdio.h>

void main()
{
    unsigned char *a;
    unsigned int *b;
    int i;

    a = (unsigned char*) malloc(12);
    b = a;

    b[0] = 0x12345678;
    b[1] = 65535;
    b[2] = 123456789;

    for(i = 0; i < 12; i++)
        printf("%x\n", a[i]);
    free(a);
}

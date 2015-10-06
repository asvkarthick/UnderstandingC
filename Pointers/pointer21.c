#include <stdio.h>

void main()
{
    int a[5][6];
    int b[5];

    printf("A     = %08x\n", a);
    printf("A + 1 = %08x\n", a + 1);

    printf("B     = %08x\n", b);
    printf("B + 1 = %08x\n", b + 1);
}

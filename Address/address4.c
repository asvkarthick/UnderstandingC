#include <stdio.h>

int main(void)
{
    int a[5], i;
    short b[5];
    char c[5];

    for(i = 0; i < 5; i++)
        printf("Address of a[%d] = %p\n", i, &a[i]);
    for(i = 0; i < 5; i++)
        printf("Address of b[%d] = %p\n", i, &b[i]);
    for(i = 0; i < 5; i++)
        printf("Address of c[%d] = %p\n", i, &c[i]);
    return 0;
}

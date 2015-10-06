#include <stdio.h>

int main(void)
{
    int a[5], i;
    short b[5];
    char c[5];

    printf("Address of a = %p\n", a);
    for(i = 0; i < 5; i++)
        printf("Address of a[%d] = %p\n", i, &a[i]);
    printf("\n");
    printf("Address of b = %p\n", b);
    for(i = 0; i < 5; i++)
        printf("Address of b[%d] = %p\n", i, &b[i]);
    printf("\n");
    printf("Address of c = %p\n", c);
    for(i = 0; i < 5; i++)
        printf("Address of c[%d] = %p\n", i, &c[i]);
    return 0;
}

#include <stdio.h>

void main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p;

    p = &a[0];
    printf("*p = %d\n", *p);
    p++;
    printf("*p = %d\n", *p);
    p = p + 5;
    printf("*p = %d\n", *p);
}

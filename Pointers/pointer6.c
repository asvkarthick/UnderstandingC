#include <stdio.h>

void main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p, i;

    p = a;
    printf("*p = %d\n", *p);
    p++;
    printf("*p = %d\n", *p);
    printf("*p = %d\n", p[5]);
    printf("*p = %d\n", *p);
    *p = 1000;
    p[-1] = 20;
    *(p + 3) = 45;
    *p++;
    printf("*p = %d\n", *p);
    *++p;
    printf("*p = %d\n", *p);

    for(i = 0; i < 10; i++)
        printf("A[%d] = %d\n", i, a[i]);
}

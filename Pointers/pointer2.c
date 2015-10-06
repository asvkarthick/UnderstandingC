#include <stdio.h>

void main()
{
    short a, *p;

    p = &a;

    printf("Address of a = %p\n", &a);
    printf("P = %p\n", p);
    p++;
    printf("P = %p\n", p);
}

#include <stdio.h>
int b = 100;

extern int a;

void func2()
{
    printf("A = %d\n", a);
}

#include <stdio.h>

extern int i;

void func2()
{
    i++;
    printf("Value of i in func2 = %d\n", i);
}

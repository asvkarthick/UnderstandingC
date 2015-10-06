#include <stdio.h>
#include <stdlib.h>

int func1()
{
    int x = 5;
    return x;
}

int* func2()
{
    int x = 5;
    return &x;
}

void main()
{
    int a, *ap;

    a  = func1();
    ap = func2();

    printf("A  = %d\n", a);
    printf("AP = %d\n", *ap);
}

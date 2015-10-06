#include <stdio.h>

unsigned char a = 1;

void func()
{
    printf("A = %d\n", a);
    a++;
}

void main()
{
    while(1)
        func();
}

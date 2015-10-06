#include <stdio.h>

int a = 1;

void func()
{
    printf("A = %d\n", a);
    a++;
    func(); // Recursive function call
}

void main()
{
    func();
}

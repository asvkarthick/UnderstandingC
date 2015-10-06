#include <stdio.h>

int a = 1;

void func()
{
    printf("Func = %d\n", a);
    a++;
}

void main()
{
    func();
    func();
    func();
    printf("A = %d\n", a);
}

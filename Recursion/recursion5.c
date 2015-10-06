#include <stdio.h>

int b = 1;

void func(int a)
{
    if(a == 5) return;
    b++;
    printf("A = %d, B = %d\n", a, b);
    func(a - 1);
}

void func2(int a)
{
    if(a == 5) return;
    func2(a - 1);
    b++;
    printf("A = %d, B = %d\n", a, b);
}

void main()
{
    func(10);
    func2(10);
}

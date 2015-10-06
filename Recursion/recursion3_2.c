#include <stdio.h>

void func(int a)
{
    if(a == 5) return;
    printf("A = %d\n", a);
    func(a - 1);
    printf("A = %d\n", a);
}

void main()
{
    func(10);
}

#include <stdio.h>

int a = 1;

void func()
{
    if(a == 5) return;
    printf("A = %d\n", a);
    a++;
    func(); // Recursive function call
}

void main()
{
    func();
}

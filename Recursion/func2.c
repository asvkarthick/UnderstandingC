#include <stdio.h>

int a = 1;

void func()
{
    printf("Func = %d\n", a);
    a++;
}

void func2()
{
    int a = 1;
    printf("Func2 = %d\n", a);
    a++;
}

void func3()
{
    static int a = 1;
    printf("Func3 = %d\n", a);
    a++;
}

void main()
{
    func();
    func();
    func();
    printf("A = %d\n", a);
    func2();
    func2();
    func2();
    printf("A = %d\n", a);
    func3();
    func3();
    func3();
}

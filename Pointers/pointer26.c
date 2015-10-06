#include <stdio.h>

void func1()
{
    printf("%s %d\n", __func__, __LINE__);
}

void func2(int a)
{
    printf("%s %d %d\n", __func__, __LINE__, a);
}

int func3(int a, int b)
{
    printf("%s %d %d %d %d\n", __func__, __LINE__, a, b, a + b);
    return a + b;
}

void main()
{
    void (*f1)();
    void (*f2)(int);
    int  (*f3)(int, int);

    f1 = func1;
    f2 = func2;
    f3 = func3;

    f1();
    f2(5);
    printf("Addition = %d\n", f3(10, 4));
}

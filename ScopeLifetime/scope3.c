#include <stdio.h>

void func()
{
    static int a = 30;
    a++;
    printf("A = %d\n", a);
}

void func2()
{
    int a = 30;
    a++;
    printf("A = %d\n", a);
}

int main(void)
{
    func();
    func();

    func2();
    func2();

    return 0;
}

#include <stdio.h>

// Global variable
int a = 10;
extern int b;

extern void func2();

void func1()
{
    printf("B = %d\n", b);
}

int main(void)
{
    printf("A = %d\n", a);

    func1();
    func2();

    return 0;
}

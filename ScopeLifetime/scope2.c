#include <stdio.h>

void func()
{
    int a = 30;
    a++;
    printf("A = %d\n", a);
}

int main(void)
{
    int a = 100;

    printf("A = %d\n", a);

    {
        int a = 20;
        printf("A = %d\n", a);
    }

    printf("A = %d\n", a);

    func();
    func();

    printf("A = %d\n", a);

    return 0;
}

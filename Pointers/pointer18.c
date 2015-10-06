#include <stdio.h>

// Call by value
void func1(int a, int b)
{
    a = 3;
    b = 6;
}

// Call by address
void func2(int *a, int *b)
{
    *a = 10;
    *b = 3;
}

void main()
{
    int x = 5, y = 2;

    printf("X = %d, Y = %d\n", x, y);

    func1(x, y);

    printf("X = %d, Y = %d\n", x, y);

    func2(&x, &y);

    printf("X = %d, Y = %d\n", x, y);
}

#include <stdio.h>

int negate(int n)
{
    n = ~n;
    n++;
    return n;
}

int main(void)
{
    int a = 1, b = 5;
    printf("a = %d, -a = %d\n", a, negate(a));
    printf("b = %d, -b = %d\n", b, negate(b));

    return 0;
}

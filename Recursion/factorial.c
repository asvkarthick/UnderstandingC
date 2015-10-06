#include <stdio.h>

int factorial(int n)
{
    if(n == 1) return 1;
    return n * factorial(n - 1);
}

void main()
{
    printf("5! = %d\n", factorial(5));
}

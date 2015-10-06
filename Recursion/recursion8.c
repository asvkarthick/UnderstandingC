#include <stdio.h>

#define N 5

void func(int n)
{
    static int i = 1;
    if(n == 0)
        return;
    printf("N = %d, I = %d\n", n, i);
    i++;
    func(n - 1);
}

void main()
{
    func(N);
}

#include<stdio.h>

int big(int a, int b)
{
    return a>b?a:b;
}

void main()
{
    int xa=7,xb=10, n;
    n=big(xa,xb);
    printf("%d\n", n);
}

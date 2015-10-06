#include <stdio.h>

void print(int i)
{
    if(i == 0) return;
    printf("i = %d\n", i);
    print(i - 1);
}

void print2(int j)
{
    if(j == 0) return;
    print2(j - 1);
    printf("j = %d\n", j);
}

void main()
{
    print(10);
    print2(10);
}

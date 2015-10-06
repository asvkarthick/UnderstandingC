#include <stdio.h>

int sumofseries(int n)
{
    if(n == 1) return 1;
    return n + sumofseries(n - 1);
}

void main()
{
    printf("Summation of 5 = %d\n", sumofseries(5));
}

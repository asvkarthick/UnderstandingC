#include <stdio.h>

int findMax(int a[], int i, int n)
{
    static int max;
    if(i == n) return max;
    if(i == 0) max = a[0];
    if(a[i] > max) max = a[i];
    findMax(a, i + 1, n);
}

void main()
{
    int b[] = {1, 2, 3, 4, 5};

    printf("Max = %d\n", findMax(b, 0, sizeof(b) / sizeof(b[0])));
}

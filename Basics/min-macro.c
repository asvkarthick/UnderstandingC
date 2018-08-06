#include <stdio.h>

#define MIN(A,B) ((A < B) ? A : B)

int main(void)
{
    int a = 5, b = 2, c;

    c = MIN(a, b);

    printf("Min = %d\n", c);
}

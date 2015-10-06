#include <stdio.h>

int main(void)
{
    int i, j;

    i = 4;
    j = i >> 1;
    printf("I = %d, J = %d\n", i, j);
    i = 4;
    j = i >> 2;
    printf("I = %d, J = %d\n", i, j);
    i = 4;
    j = i >> 3;
    printf("I = %d, J = %d\n", i, j);

    
    i = 4;
    j = i << 1;
    printf("I = %d, J = %d\n", i, j);
    i = 4;
    j = i << 2;
    printf("I = %d, J = %d\n", i, j);
    i = 4;
    j = i << 3;
    printf("I = %d, J = %d\n", i, j);

    return 0;
}

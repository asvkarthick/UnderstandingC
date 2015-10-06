#include <stdio.h>

int main(void)
{
    char i = 20;
    char j;

    j = !i;
    printf("I = %d, J = %d\n", i, j);
    j = !!i;
    printf("I = %d, J = %d\n", i, j);
    j = !!!i;
    printf("I = %d, J = %d\n", i, j);
    i = 0;
    j = !i;
    printf("I = %d, J = %d\n", i, j);
    return 0;
}

#include <stdio.h>

int main(void)
{
    int i, j = 5;
    i = j++ + j++;
    printf("I = %d, J = %d\n", i, j);
    i = j++ + j++;
    printf("I = %d, J = %d\n", i, j);
    return 0;
}

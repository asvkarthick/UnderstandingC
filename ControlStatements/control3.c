#include <stdio.h>

int main(void)
{
    int i = 5;

    if((i & 1) == 0)
        printf("%d is even number.\n", i);
    else
        printf("%d is odd number.\n", i);

    return 0;
}

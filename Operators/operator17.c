#include <stdio.h>

int main(void)
{
    int a, b, c;

    a = 5; b = 0;

    if(b = 6)
        printf("A = %d, B = %d\n", a, b);

    if((a == 5) || (b = 7))
        printf("A = %d, B = %d\n", a, b);
    return 0;
}

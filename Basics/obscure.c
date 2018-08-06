#include <stdio.h>

int main(void)
{
    int a = 5, b = 7, c;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    c = a+++b;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("C = %d\n", c);

    return 0;
}

#include <stdio.h>

int main(void)
{
    int a, b, c;

    a = b = 0;
    c = a && b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    a = b = 5;
    c = a && b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    a = 0; b = 5;
    c = a && b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    a = 5; b = 0;
    c = a && b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    return 0;
}

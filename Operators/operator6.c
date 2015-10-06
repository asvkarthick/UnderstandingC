#include <stdio.h>

int main(void)
{
    int a = 11, b = 2, c;

    c = a + b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a - b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a * b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a / b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a % b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);

    return 0;
}

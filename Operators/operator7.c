#include <stdio.h>

int main(void)
{
    char a = 111, b = 20, c;

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

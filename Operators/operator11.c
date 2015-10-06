#include <stdio.h>

int main(void)
{
    char a = -1, b = 112, c;

    c = a & b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a | b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a ^ b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = !a;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = !b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = ~a;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = ~!a;
    printf("A = %d, B = %d, C = %d\n", a, b, c);

    return 0;
}

#include <stdio.h>

int main(void)
{
    char a = 33, b = 31, c;

    c = a & b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a | b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
    c = a ^ b;
    printf("A = %d, B = %d, C = %d\n", a, b, c);
}

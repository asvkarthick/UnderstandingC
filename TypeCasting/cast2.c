#include <stdio.h>

int main(void)
{
    int a = 1000;
    short b;
    char c;
    float d;

    d = b = c = a;

    printf("A = %d, B = %d, C = %d, D = %f\n", a, b, c, d);

    return 0;
}

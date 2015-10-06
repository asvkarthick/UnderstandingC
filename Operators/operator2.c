#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    
    a = 10;
    b = 5;
    c = 3;

    d = a * b / c;
    e = (a * b) / c;
    f = a * (b / c);

    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("C = %d\n", c);
    printf("D = %d\n", d);
    printf("E = %d\n", e);
    printf("F = %d\n", f);

    return 0;
}

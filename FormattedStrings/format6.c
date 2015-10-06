#include <stdio.h>

int main(void)
{
    int i = 20;
    float f = 3.141234;

    printf("I = %d\n", i);
    printf("I = %5d\n", i);
    printf("I = %-5d\n", i);
    printf("I = %05d\n", i);

    printf("F = %f\n", f);
    printf("F = %5f\n", f);
    printf("F = %5.2f\n", f);
    printf("F = %-5.2f\n", f);
    return 0;
}

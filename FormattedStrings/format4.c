#include <stdio.h>

int main(void)
{
    float f = 3.141234;
    printf("F = %f\n", f);
    printf("F = %10f\n", f);
    printf("F = %10.2f\n", f);
    printf("F = %10.5f\n", f);

    f = 10.0 / 3.0;
    printf("F = %f\n", f);
    printf("F = %10f\n", f);
    printf("F = %10.2f\n", f);
    printf("F = %10.5f\n", f);
    return 0;
}

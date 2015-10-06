#include <stdio.h>

int main(void)
{
    float f = 2.0;
    int *i = (int*) &f;
    printf("F = %f, I = %x\n", f, *i);
    f = 0.5;
    printf("F = %f, I = %x\n", f, *i);
    return 0;
}

#include <stdio.h>

int main(void)
{
    float f = 5.75f;
    int *i = (int*) &f;
    printf("F = %f, I = %x\n", f, *i);
    return 0;
}

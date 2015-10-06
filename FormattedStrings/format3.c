#include<stdio.h>

int main(void)
{
    int i = 20;
    printf("I = %d\n", i);
    printf("I = %4d\n", i);
    printf("I = %04d\n", i);
    i = 12345678;
    printf("I = %04d\n", i);
    return 0;
}

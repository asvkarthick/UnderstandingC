#include <stdio.h>

int main(void)
{
    // Program to set bits 0, 2, 4, 7 in a char variable
    unsigned char  ch = 0;

    ch = ch | (1 << 0) | (1 << 2) | (1 << 4) | (1 << 7);
    printf("Ch = %x\n", ch);

    return 0;
}

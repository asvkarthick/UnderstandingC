#include <stdio.h>

int main(void)
{
    // Program to toggle bits
    unsigned char ch = 0xA5;
    ch = ~ch;
    printf("Ch = %x\n", ch);

    return 0;
}

#include <stdio.h>

// Program to swap bit-1 with bit-0, bit-3 with bit-2, bit-5 with bit-4, bit-7 with bit-6
int main(void)
{
    unsigned char ch = 0xEB;
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7;

    b0 = ch & 1;
    b1 = (ch & (1 << 1)) >> 1;
    b2 = (ch & (1 << 2)) >> 2;
    b3 = (ch & (1 << 3)) >> 3;
    b4 = (ch & (1 << 4)) >> 4;
    b5 = (ch & (1 << 5)) >> 5;
    b6 = (ch & (1 << 6)) >> 6;
    b7 = (ch & (1 << 7)) >> 7;
    ch = (b0 << 1) | b1 | (b2 << 3) | (b3 << 2) | (b4 << 5) | (b5 << 4) | (b6 << 7) | (b7 << 6);

    printf("Ch = %x\n", ch);
    return 0;
}

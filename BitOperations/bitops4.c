#include <stdio.h>

// Program to swap bit-1 with bit-0, bit-3 with bit-2, bit-5 with bit-4, bit-7 with bit-6
int main(void)
{
    unsigned char ch = 0xEB;

    ch = ((ch & 1) << 1) |
         ((ch & (1 << 1)) >> 1) |
         ((ch & (1 << 2)) << 1) |
         ((ch & (1 << 3)) >> 1) |
         ((ch & (1 << 4)) << 1) |
         ((ch & (1 << 5)) >> 1) |
         ((ch & (1 << 6)) << 1) |
         ((ch & (1 << 7)) >> 1);
    printf("Ch = %x\n", ch);
    return 0;
}

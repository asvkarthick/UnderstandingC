#include<stdio.h>

int main()
{
    int i = 0xABCDEF21;
    
    printf(" digit 0 = %x\n", i & 0xf);
    printf(" digit 1 = %x\n", (i & 0xf0) >> 4);
    printf(" digit 2 = %x\n", (i & 0xf00) >> 8);
    printf(" digit 3 = %x\n", (i & 0xf000) >> 12);

    printf(" digit 4 = %x\n", (i & 0xf0000) >> 16);
    printf(" digit 5 = %x\n", (i & 0xf00000) >> 20);
    printf(" digit 6 = %x\n", (i & 0xf000000) >> 24);
    printf(" digit 7 = %x\n", (i & 0xf0000000) >> 28);

    return 0;
}

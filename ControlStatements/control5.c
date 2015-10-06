#include<stdio.h>

int main()
{
    char ch = 0xA5;
    
    printf(" bit 0 = %d\n", ch & 0x01);
    printf(" bit 1 = %d\n", (ch & 0x02) >> 1);
    printf(" bit 2 = %d\n", (ch & 0x04) >> 2);
    printf(" bit 3 = %d\n", (ch & 0x08) >> 3);
    printf(" bit 4 = %d\n", (ch & 0x10) >> 4);
    printf(" bit 5 = %d\n", (ch & 0x20) >> 5);
    printf(" bit 6 = %d\n", (ch & 0x40) >> 6);
    printf(" bit 7 = %d\n", (ch & 0x80) >> 7);

    return 0;
}

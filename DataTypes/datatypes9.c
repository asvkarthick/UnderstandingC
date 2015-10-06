#include <stdio.h>

int main(void)
{
    signed int ch;
    ch = 0x07;
    printf("Ch = %d\n", ch);
    ch = 0xFFFFFFF9;
    printf("Ch = %d\n", ch);
    ch = 0xFFFFFFF1;
    printf("Ch = %d\n", ch);
    ch = 0xFFFFffE0;
    printf("Ch = %d\n", ch);
    return 0;
}

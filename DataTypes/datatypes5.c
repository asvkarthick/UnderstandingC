#include <stdio.h>

int main(void)
{
    short ch;
    ch = 0x07;
    printf("Ch = %d\n", ch);
    ch = 0xFFF9;
    printf("Ch = %d\n", ch);
    ch = 0xFFF1;
    printf("Ch = %d\n", ch);
    ch = 0xffE0;
    printf("Ch = %d\n", ch);
    return 0;
}

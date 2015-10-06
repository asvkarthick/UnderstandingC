#include <stdio.h>

int main(void)
{
    signed short ch;
    ch = 0x07;
    printf("Ch = %d\n", ch);
    ch = 0x1234FFF9;
    printf("Ch = %d\n", ch);
    ch = 0x1234FFF1;
    printf("Ch = %d\n", ch);
    ch = 0x1234FfE0;
    printf("Ch = %d\n", ch);
    return 0;
}

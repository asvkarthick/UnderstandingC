#include <stdio.h>

int main(void)
{
    unsigned char ch;
    ch = 0x07;
    printf("Ch = %d\n", ch);
    ch = 0x4321FFF9;
    printf("Ch = %d\n", ch);
    ch = 0x4321FFF1;
    printf("Ch = %d\n", ch);
    ch = 0x4321FfE0;
    printf("Ch = %d\n", ch);
    return 0;
}

#include <stdio.h>

int main(void)
{
    unsigned int ch;
    ch = 0x07;
    printf("Ch = %d\n", ch);
    ch = 0xFFFFFFF9;
    printf("Ch = %d\n", ch);
    ch = 0xFFFFFFF1;
    printf("Ch = %d\n", ch);
    ch = 0xfFFFFfE0;
    printf("Ch = %d\n", ch);
    return 0;
}

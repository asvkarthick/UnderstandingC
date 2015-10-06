#include <stdio.h>

int main(void)
{
    char ch;

    ch = 127;
    printf("Ch = %d, %x\n", ch, ch);
    ch = ch + 1;
    printf("Ch = %d, %x\n", ch, ch);

    return 0;
}

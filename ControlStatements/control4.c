#include <stdio.h>

int main(void)
{
    int i = 4;
    char c = -7;
    short s = 25;

    if(i & 0x80000000)
        printf("%d is -ve number.\n", i);
    else
        printf("%d is +ve number.\n", i);

    if(c & 0x80)
        printf("%d is -ve number.\n", c);
    else
        printf("%d is +ve number.\n", c);

    if(s & 0x8000)
        printf("%d is -ve number.\n", s);
    else
        printf("%d is +ve number.\n", s);

    return 0;
}

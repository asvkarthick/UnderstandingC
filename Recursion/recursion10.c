#include <stdio.h>

void printBits(unsigned int num)
{
    static int i = 0;

    if(i == sizeof(num) * 8)
    {
        printf("\n");
        return;
    }
    printf("%d", (num & (1 << (31 - i))) >> (31 - i));
    i++;
    printBits(num);
}

void main()
{
    printBits(32);
}

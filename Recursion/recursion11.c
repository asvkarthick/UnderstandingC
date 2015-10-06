#include <stdio.h>

int getRemainder(int x, int y)
{
    if(x < y)
        return x;
    getRemainder(x - y, y);
}

void main()
{
    printf("Remainder of 200 / 7 (or) 200 % 7 = %d\n", getRemainder(200, 7));
}

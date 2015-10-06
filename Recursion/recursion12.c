#include <stdio.h>

int getQuotient(int x, int y, int quotient)
{
    if(x < y) return quotient;
    return getQuotient(x-y, y,quotient+1);
}

void main()
{
    printf("Quotient of 200 / 7 (or) 200 % 7 = %d\n", getQuotient(200, 7,0));
    printf("Quotient of 16/3 (or) 16 % 3 = %d\n", getQuotient(16, 3,0));
}

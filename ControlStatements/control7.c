#include<stdio.h>

int main()
{
    int i = 0xABCDEF21;
    
    printf(" byte  0 = %x\n", i & 0xff);
    printf(" byte  1 = %x\n", (i & 0xff00) >> 8);
    printf(" byte  2 = %x\n", (i & 0xff0000) >> 16 );
    printf(" byte  3 = %x\n", (i & 0xff000000) >> 24);

    return 0;
}

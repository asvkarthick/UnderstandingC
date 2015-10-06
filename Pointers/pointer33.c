#include <stdio.h>

void main()
{
    char* cptr = 0x12345678;
    short *s;

    s = (short*)(short)(short*)cptr;
    printf("S = %08x\n", s);
}

#include <stdio.h>

void main()
{
    int n = 0x12345678;
    const char *p1 = (const char*)&n;
    char* const p2 = (char* const) &n;

    p1++;
    *p2 = 10;
    printf("N = %08x\n", n);
}

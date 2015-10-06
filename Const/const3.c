#include <stdio.h>

void main()
{
    int n = 0x12345678;
    // Pointer to a constant
    const char *p1 = (const char*)&n;
    // Constant pointer
    char* const p2 = (char* const) &n;

    p1++;
    // Following statement will lead to error as p1 is pointer to a constant
    //*p1 = 20;
    *p2 = 10;
    // Following statement will lead to error as p2 is constant pointer
    // p2++;
    printf("N = %08x\n", n);
}

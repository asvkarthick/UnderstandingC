#include <stdio.h>

void main()
{
    int a[10] = {0x01020304, 0x05060708, 0x090a0b0c0d, 0x0e0f1011, 0x12131415,
                 0x16171819, 0x1a1b1c1d, 0x1e1f202122, 0x23242526, 0x27282930};
    char *cp;
    short *sp;
    int *ip;
    int i;

    cp = a;
    sp = a;
    ip = a;

    for(i = 0; i < 5; i++)
    {
        printf("cp = %p, *cp = %x\n", cp, *cp);
        printf("sp = %p, *sp = %x\n", sp, *sp);
        printf("ip = %p, *ip = %x\n", ip, *ip);
        cp++; sp++; ip++;
    }
}

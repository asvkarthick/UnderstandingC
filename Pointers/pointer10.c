#include <stdio.h>

void main()
{
    char a[] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x99, 0x98, 0x97, 0x96};
    int *ip;
    short *sp;
    char *cp;

    cp = sp = ip = a;

    printf(" cp = %08x,  sp = %08x,  ip = %08x\n", cp, sp, ip);

    printf("*cp = %08x, *sp = %08x, *ip = %08x\n", *cp, *sp, *ip);

    cp++;
    sp++;
    ip++;

    printf("*cp = %08x, *sp = %08x, *ip = %08x\n", *cp, *sp, *ip);
}

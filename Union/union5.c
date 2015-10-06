#include <stdio.h>

union
{
    int a;

    struct
    {
        char a;
        char b;
        char c;
        char d;
    } s1;

    struct
    {
        short a;
        short b;
    } s2;
} u;

int main(void)
{
    printf("Addr of u      = %p\n", &u);
    printf("Addr of u.a    = %p\n", &u.a);
    printf("Addr of u.s1.a = %p\n", &u.s1.a);
    printf("Addr of u.s1.b = %p\n", &u.s1.b);
    printf("Addr of u.s1.c = %p\n", &u.s1.c);
    printf("Addr of u.s1.d = %p\n", &u.s1.d);
    printf("Addr of u.s2.a = %p\n", &u.s2.a);
    printf("Addr of u.s2.b = %p\n", &u.s2.b);

    u.s1.a = 0x12;
    u.s1.b = 0x34;
    u.s1.c = 0x56;
    u.s1.d = 0x78;

    printf("U.A    = %08x\n", u.a);
    printf("U.S1.A = %08x\n", u.s1.a);
    printf("U.S1.B = %08x\n", u.s1.b);
    printf("U.S1.C = %08x\n", u.s1.c);
    printf("U.S1.D = %08x\n", u.s1.d);
    printf("U.S2.A = %08x\n", u.s2.a);
    printf("U.S2.B = %08x\n", u.s2.b);
    return 0;
}

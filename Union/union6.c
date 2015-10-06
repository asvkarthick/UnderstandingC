#include <stdio.h>

union uni
{
    short a;
    struct str
    {
        short a : 16;
        short b : 16;
    } s;
} u;

int main(void)
{
    u.a = 0x78FF;

    printf("Size of u = %d\n", sizeof(u));
    
    printf("Address of u     = %p\n", &u);
    printf("Address of u.a   = %p\n", &u.a);
    printf("Address of u.s   = %p\n", &u.s);

    printf("U.A   = %08x\n", u.a);
    printf("U.S.A = %08x\n", u.s.a);
    printf("U.S.B = %08x\n", u.s.b);

    return 0;
}

#include <stdio.h>

union uni
{
    char a;
    short b;
    int c;
} u;

int main(void)
{
    u.a = 0x10;
    printf("A = %08x, B = %08x, C = %08x\n", u.a, u.b, u.c);
    u.b = 0x1234;
    printf("A = %08x, B = %08x, C = %08x\n", u.a, u.b, u.c);
    u.c = 0x12345678;
    printf("A = %08x, B = %08x, C = %08x\n", u.a, u.b, u.c);
    u.a = 0x12;
    printf("A = %08x, B = %08x, C = %08x\n", u.a, u.b, u.c);
    u.b = 0x1234;
    printf("A = %08x, B = %08x, C = %08x\n", u.a, u.b, u.c);

    return 0;
}

#include <stdio.h>

struct str
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

void main()
{
    struct str s, *sptr;
    unsigned int arr[] = {0x12345678, 0x87654321, 0x90ABCDEF};

    sptr = &s;
    s.a = 0x10002000;
    s.b = 0x30004000;
    s.c = 0x50006000;

    printf("S.A = %08x, S.B = %08x, S.C = %08x\n", s.a, s.b, s.c);
    printf("(*sptr).a = %08x, (*sptr).b = %08x, (*sptr).c = %08x\n", (*sptr).a, (*sptr).b, (*sptr).c);
    printf("SPTR->A = %08x, SPTR->B = %08x, SPTR->C = %08x\n", sptr->a, sptr->b, sptr->c);

    // unsigned int arr[] is equal to unsigned int*
    sptr = (struct str*) arr;
    printf("(*sptr).a = %08x, (*sptr).b = %08x, (*sptr).c = %08x\n", (*sptr).a, (*sptr).b, (*sptr).c);
    printf("SPTR->A = %08x, SPTR->B = %08x, SPTR->C = %08x\n", sptr->a, sptr->b, sptr->c);
}

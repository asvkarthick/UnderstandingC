#include <stdio.h>

struct str1
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};

struct str2
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

void main()
{
    unsigned int i = 0x12345678;
    struct str1 *s1;
    struct str2 *s2;
    char str[] = "Karthick Kumaran";
    unsigned int *iptr;
    struct str2 sv2;

    s1 = (struct str1*) &i;
    s2 = (struct str2*) str;

    sv2.a = 0x10002000;
    sv2.b = 0x30004000;
    sv2.c = 0x50006000;
    sv2.d = 0x70008000;

    iptr = (unsigned int*) &sv2;

    printf("S1->A = %x\n", s1->a);
    printf("S1->B = %x\n", s1->b);
    printf("S1->C = %x\n", s1->c);
    printf("S1->D = %x\n", s1->d);

    printf("S2->A = %08x\n", s2->a);
    printf("S2->B = %08x\n", s2->b);
    printf("S2->C = %08x\n", s2->c);
    printf("S2->D = %08x\n", s2->d);

    printf("*iptr       = %08x\n", *iptr);
    printf("*(iptr + 1) = %08x\n", *(iptr + 1));
    printf("*(iptr + 2) = %08x\n", *(iptr + 2));
    printf("*(iptr + 3) = %08x\n", *(iptr + 3));

    s2 = (struct str2*) iptr;

    printf("S2->A = %08x\n", s2->a);
    printf("S2->B = %08x\n", s2->b);
    printf("S2->C = %08x\n", s2->c);
    printf("S2->D = %08x\n", s2->d);
}

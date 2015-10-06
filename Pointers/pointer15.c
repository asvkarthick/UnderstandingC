#include <stdio.h>

struct str1
{
    unsigned char a;
    unsigned short b;
    int c;
};

struct str2
{
    struct str1 s;
    int d;
    int e;
};

struct str3
{
    struct str2 *s;
    int f;
    int g;
};

void main()
{
    int arr[] = {0x12345678, 0x87654321, 0x10203040, 0x50607080, 0x0a0b0c0d};
    int arr2[] = {0x12345678, 0x87654321, 0x10203040, 0x50607080, 0x0a0b0c0d};
    struct str1 *s1;
    struct str2 *s2;
    struct str3 *s3;

    s1 = (struct str1*) &arr[0];
    s2 = (struct str2*) arr;
    s3 = (struct str3*) arr2;
    s3->s = (struct str2*) s2;

    printf("S1->A      = %08x, %d\n", s1->a, s1->a);
    printf("S1->B      = %08x, %d\n", s1->b, s1->b);
    printf("S1->C      = %08x, %d\n", s1->c, s1->c);

    printf("S2->s.a    = %08x\n", s2->s.a);
    printf("S2->s.b    = %08x\n", s2->s.b);
    printf("S2->s.c    = %08x\n", s2->s.c);

    printf("S3->S->S.A = %08x\n", s3->s->s.a);
    printf("S3->S->S.B = %08x\n", s3->s->s.b);
    printf("S3->S->S.C = %08x\n", s3->s->s.c);
    printf("S3->S->D   = %08x\n", s3->s->d);
    printf("S3->S->E   = %08x\n", s3->s->e);
    printf("S3->F      = %08x\n", s3->f);
    printf("S3->G      = %08x\n", s3->g);
}

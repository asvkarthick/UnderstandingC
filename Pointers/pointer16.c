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
    s3 = (struct str3*) s2;
    s3->s = (struct str2*) s2;

    printf("ARR  = %08x, &arr[0]  = %08x\n", arr, &arr[0]);
    printf("ARR2 = %08x, &arr2[0] = %08x\n", arr2, &arr2[0]);
    printf("S1->A       = %08x\n", s1->a);
    printf("S1->B       = %08x\n", s1->b);
    printf("S1->C       = %08x\n", s1->c);

    printf("S2->s.a     = %08x\n", s2->s.a);
    printf("S2->s.b     = %08x\n", s2->s.b);
    printf("S2->s.c     = %08x\n", s2->s.c);

    printf("S3->S->S.A  = %08x\n", s3->s->s.a);
    printf("S3->S->S.B  = %08x\n", s3->s->s.b);
    printf("S3->S->S.C  = %08x\n", s3->s->s.c);
    printf("S3->S->D    = %08x\n", s3->s->d);
    printf("S3->S->E    = %08x\n", s3->s->e);
    printf("S3->F       = %08x\n", s3->f);
    printf("S3->G       = %08x\n", s3->g);

    printf("&s1         = %p\n", &s1);
    printf("&s1->a      = %p\n", &s1->a);
    printf("&s1->b      = %p\n", &s1->b);
    printf("&s1->c      = %p\n", &s1->c);

    printf("&s2->s.a    = %p\n", &s2->s.a);
    printf("&s2->s.b    = %p\n", &s2->s.b);
    printf("&s2->s.c    = %p\n", &s2->s.c);

    printf("&s3->s->s.a = %p\n", &s3->s->s.a);
    printf("&s3->s->s.b = %p\n", &s3->s->s.b);
    printf("&s3->s->s.c = %p\n", &s3->s->s.c);
    printf("&s3->s->d   = %p\n", &s3->s->d);
    printf("&s3->s->e   = %p\n", &s3->s->e);
    printf("&s3->f      = %p\n", &s3->f);
    printf("&s3->g      = %p\n", &s3->g);

    s1 = (struct str1*) arr2;
    s2 = (struct str2*) arr2;
    s3 = (struct str3*) arr2;
    s3->s = (struct str2*) arr;

    printf("&s1         = %p\n", &s1);
    printf("&s1->a      = %p\n", &s1->a);
    printf("&s1->b      = %p\n", &s1->b);
    printf("&s1->c      = %p\n", &s1->c);

    printf("&s2->s.a    = %p\n", &s2->s.a);
    printf("&s2->s.b    = %p\n", &s2->s.b);
    printf("&s2->s.c    = %p\n", &s2->s.c);

    printf("&s3->s->s.a = %p\n", &s3->s->s.a);
    printf("&s3->s->s.b = %p\n", &s3->s->s.b);
    printf("&s3->s->s.c = %p\n", &s3->s->s.c);
    printf("&s3->s->d   = %p\n", &s3->s->d);
    printf("&s3->s->e   = %p\n", &s3->s->e);
    printf("&s3->f      = %p\n", &s3->f);
    printf("&s3->g      = %p\n", &s3->g);
}

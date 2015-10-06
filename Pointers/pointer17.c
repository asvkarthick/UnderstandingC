#include <stdio.h>

struct str
{
    char a;
    short b;
    int c;
};

void main()
{
    struct str s1, s2, *sp1 = NULL, *sp2 = NULL;

    printf("&s1     = %p\n", &s1);
    printf("&s1.a   = %p\n", &s1.a);
    printf("&s1.b   = %p\n", &s1.b);
    printf("&s1.c   = %p\n", &s1.c);

    printf("&s2     = %p\n", &s2);
    printf("&s2.a   = %p\n", &s2.a);
    printf("&s2.b   = %p\n", &s2.b);
    printf("&s2.c   = %p\n", &s2.c);

    printf("sp1     = %p\n", sp1);
    printf("&sp1    = %p\n", &sp1);
    printf("&sp1->a = %p\n", &sp1->a);
    printf("&sp1->b = %p\n", &sp1->b);
    printf("&sp1->c = %p\n", &sp1->c);

    printf("sp2     = %p\n", sp2);
    printf("&sp2    = %p\n", &sp2);
    printf("&sp2->a = %p\n", &sp2->a);
    printf("&sp2->b = %p\n", &sp2->b);
    printf("&sp2->c = %p\n", &sp2->c);

    sp1 = &s1;
    sp2 = &s2;

    printf("sp1     = %p\n", sp1);
    printf("&sp1    = %p\n", &sp1);
    printf("&sp1->a = %p\n", &sp1->a);
    printf("&sp1->b = %p\n", &sp1->b);
    printf("&sp1->c = %p\n", &sp1->c);

    printf("sp2     = %p\n", sp2);
    printf("&sp2    = %p\n", &sp2);
    printf("&sp2->a = %p\n", &sp2->a);
    printf("&sp2->b = %p\n", &sp2->b);
    printf("&sp2->c = %p\n", &sp2->c);
}

#include <stdio.h>

struct str6
{
    char  a;
    int   b;
    short c;
};

int main(void)
{
    struct str6 s[3];
    
    printf("Size of struct str6 = %d\n", sizeof(struct str6));
    printf("Size of s = %d\n", sizeof(s));

    printf("Addr of s = %p\n", s);
    printf("Addr of s[0] = %p\n", &s[0]);
    printf("Addr of s[1] = %p\n", &s[1]);
    printf("Addr of s[2] = %p\n", &s[2]);
    printf("\n");

    printf("Addr of s[0].a = %p\n", &s[0].a);
    printf("Addr of s[0].b = %p\n", &s[0].b);
    printf("Addr of s[0].c = %p\n", &s[0].c);
    printf("\n");
    printf("Addr of s[1].a = %p\n", &s[1].a);
    printf("Addr of s[1].b = %p\n", &s[1].b);
    printf("Addr of s[1].c = %p\n", &s[1].c);
    printf("\n");
    printf("Addr of s[2].a = %p\n", &s[2].a);
    printf("Addr of s[2].b = %p\n", &s[2].b);
    printf("Addr of s[2].c = %p\n", &s[2].c);
    printf("\n");

    return 0;
}

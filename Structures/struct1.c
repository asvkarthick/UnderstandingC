#include <stdio.h>

struct str
{
    int a;
    int b;
}s;

struct str2
{
    int a;
    short b;
    short c;
}s2;

struct str3
{
    short a;
    char b;
    char c;
}s3;

int main(void)
{
    printf("Address of s = %p\n", &s);
    printf("Address of s.a = %p\n", &s.a);
    printf("Address of s.b = %p\n", &s.b);
    printf("\n");

    printf("Address of s2 = %p\n", &s2);
    printf("Address of s2.a = %p\n", &s2.a);
    printf("Address of s2.b = %p\n", &s2.b);
    printf("Address of s2.c = %p\n", &s2.c);
    printf("\n");

    printf("Address of s3 = %p\n", &s3);
    printf("Address of s3.a = %p\n", &s3.a);
    printf("Address of s3.b = %p\n", &s3.b);
    printf("Address of s3.c = %p\n", &s3.c);
    printf("\n");
}

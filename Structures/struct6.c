#include <stdio.h>

struct str1
{
    int a;
    char b;
    int c;
};

struct str2
{
    int a;
    char b;
    int c;
} __attribute__((packed));

struct str3
{
    int a;
    char b;
};

struct str4
{
    int a;
    char b;
} __attribute__((packed));

void main()
{
    printf("Size of str1 = %d\n", sizeof(struct str1));
    printf("Size of str2 = %d\n", sizeof(struct str2));
    printf("Size of str3 = %d\n", sizeof(struct str3));
    printf("Size of str4 = %d\n", sizeof(struct str4));
}

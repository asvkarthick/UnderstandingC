#include<stdio.h>

union uni1
{
    int a;
    char b;
    short c;
} u1;

union uni2
{
    int a;
    int b;
    int c;
} u2;

union uni3
{
    char a;
    short b;
} u3;

union uni4
{
    short a;
    int c;
} u4;

int main(void)
{
    printf("Size of union1 = %d\n", sizeof(u1));
    printf("Size of union2 = %d\n", sizeof(u2));
    printf("Size of union3 = %d\n", sizeof(u3));
    printf("Size of union4 = %d\n", sizeof(u4));

    return 0;
}

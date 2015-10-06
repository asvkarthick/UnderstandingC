#include <stdio.h>

struct str3
{
    char a;
    short b;
};

struct str4
{
    char a;
    int b;
    short c;
};

int main(void)
{
    printf("Size of struct str3 = %d\n", sizeof(struct str3));
    printf("Size of struct str4 = %d\n", sizeof(struct str4));
    return 0;
}

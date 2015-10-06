#include <stdio.h>

struct str
{
    short a;
    int b;
};

struct str2
{
    short a;
    short b;
    int c;
};

int main(void)
{
    printf("Size of struct str  = %d\n", sizeof(struct str));
    printf("Size of struct str2 = %d\n", sizeof(struct str2));
    return 0;
}

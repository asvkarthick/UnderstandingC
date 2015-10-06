#include <stdio.h>

struct str5
{
    short a;
    long long b;
    int c;
    char d;
};

int main(void)
{
    printf("Size of struct str5 = %d\n", sizeof(struct str5));
    return 0;
}

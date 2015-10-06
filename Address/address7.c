#include <stdio.h>

struct str
{
    int a;
    int b;
};

int main(void)
{
    struct str s;

    printf("Sizeof s = %d\n", sizeof(s));
    printf("Addr of s = %p\n", &s);
    printf("Addr of s.a = %p\n", &s.a);
    printf("Addr of s.b = %p\n", &s.b);

    return 0;
}

#include <stdio.h>

union uni
{
    char a;
    short b;
    int c;
} u;

int main(void)
{
    printf("Address of u   = %p\n", &u);
    printf("Address of u.a = %p\n", &u.a);
    printf("Address of u.b = %p\n", &u.b);
    printf("Address of u.c = %p\n", &u.c);

    return 0;
}

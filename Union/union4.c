#include<stdio.h>

union uni
{
    char a[4];
    int b;
    short c[2];
};

int main(void)
{
    union uni u;

    printf("Addr of a[0] = %p\n", &u.a[0]);
    printf("Addr of a[1] = %p\n", &u.a[1]);
    printf("Addr of a[2] = %p\n", &u.a[2]);
    printf("Addr of a[3] = %p\n", &u.a[3]);
    printf("Addr of B    = %p\n", &u.b);
    printf("Addr of c[0] = %p\n", &u.c[0]);
    printf("Addr of c[1] = %p\n", &u.c[1]);
    u.b = 0x12345678;

    printf("A[0] = %x\n", u.a[0]);
    printf("A[1] = %x\n", u.a[1]);
    printf("A[2] = %x\n", u.a[2]);
    printf("A[3] = %x\n", u.a[3]);
    printf("B = %x\n",u.b);
    printf("C[0] = %x\n", u.c[0]);
    printf("C[1] = %x\n", u.c[1]);

    return 0;
}

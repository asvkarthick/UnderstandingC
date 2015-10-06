#include <stdio.h>

void main()
{
    int a = 0x12345678;
    int *ptr;

    ptr = &a;

    printf("A            = %08x\n", a);
    printf("*ptr         = %08x\n", *ptr);
    printf("*(char*)ptr  = %08x\n", *(char*)ptr);
    printf("*(short*)ptr = %08x\n", *(short*)ptr);
    printf("*(int*)ptr   = %08x\n", *(int*)ptr);
}

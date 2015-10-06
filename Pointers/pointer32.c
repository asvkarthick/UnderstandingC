#include <stdio.h>

void main()
{
    int n = 123456789;
    char *ptr;

    ptr = (char*) &n;

    printf("*ptr       = %d, %x\n", *ptr, *ptr);
    printf("*(ptr + 1) = %d, %x\n", *(ptr + 1), *(ptr + 1));
    printf("*(ptr + 2) = %d, %x\n", *(ptr + 2), *(ptr + 2));
    printf("*(ptr + 3) = %d, %x\n", *(ptr + 3), *(ptr + 3));
}

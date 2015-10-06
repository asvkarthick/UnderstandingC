#include <stdio.h>

void main()
{
    char arr[] = {0x12, 0x34, 0x56, 0x78, 12, 34, 56, 78, 0x87, 0x65, 0x43, 0x21, 87, 65, 43, 21};
    int *ptr;

    ptr = (int*)arr;
    ptr++;
    printf("*ptr         = %08x\n", *ptr);
    printf("*ptr         = %d\n", *ptr);
    printf("*(char*)ptr  = %d\n", *(char*)ptr);
    printf("*(char*)ptr  = %08x\n", *(char*)ptr);
    printf("*(short*)ptr = %08x\n", *(short*)(ptr + 1));
}

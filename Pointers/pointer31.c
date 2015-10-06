#include <stdio.h>

void main()
{
    char arr[] = {0x12, 0x34, 0x56, 0x78, 12, 34, 56, 78, 0x87, 0x65, 0x43, 0x21, 87, 65, 43, 21};
    int *ptr;

    ptr = (int*)arr;
    ptr++; ptr++; ptr++;

    printf("*(short*)ptr              = %08x\n", *(short*)ptr);
    printf("*(short*)ptr              = %d\n", *(short*)ptr);
    printf("*(char*)(((int)ptr) + 1)  = %08x\n", *(char*)(((int)ptr) + 1));
    printf("*(short*)(((int)ptr) + 2) = %08x\n", *(short*)(((int)ptr) + 2));
}

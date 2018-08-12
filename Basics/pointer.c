#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int (*ptr)[10] = &arr;
    int *ptr2 = arr;

    printf("%d\n", **ptr);
    printf("%d\n", *ptr2);

    printf("ptr = %p, ptr + 1 = %p\n", ptr, ptr + 1);
    printf("ptr2 = %p, ptr2 + 1 = %p\n", ptr2, ptr2 + 1);

    return 0;
}

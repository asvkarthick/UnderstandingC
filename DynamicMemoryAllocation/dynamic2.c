#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *ptr = NULL;
    char *ptr2;

    printf("Ptr = %p\n", ptr);
    ptr = (char*) malloc(100);

    // Copy the pointer value to another pointer
    ptr2 = ptr;
    printf("Ptr = %p\n", ptr);
    printf("Ptr2 = %p\n", ptr2);

    free(ptr);
    free(ptr2);
}

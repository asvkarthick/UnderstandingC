#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *ptr1 = NULL, *ptr2 = NULL;

    printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);

    ptr1 = (char*) malloc(100);
    ptr2 = (char*) malloc(50);

    printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);

    ptr2 = ptr1;
    // Now we have lost the original value of ptr2
    // The memory address which was originally pointed can never be deallocated
    printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);

    free(ptr1);

    // We should not access the memory location after we have deallocated that
    *ptr1 = 10;
    *ptr2 = 20;
    // ptr2 will now become DANGLING POINTER
    printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);
}

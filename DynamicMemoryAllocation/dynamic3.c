#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *ptr1 = NULL, *ptr2 = NULL;

    printf("****************** START *******************\n");
    printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);

    // while(1)
    {
        ptr1 = (char*) malloc(10000);
        ptr2 = (char*) malloc(50000);

        if(ptr1 == NULL)
            printf("Memory not available : ptr1\n");

        if(ptr2 == NULL)
            printf("Memory not available : ptr2\n");

        printf("Ptr1 = %p, Ptr2 = %p\n", ptr1, ptr2);
        printf("****************** END *******************\n\n\n");

        free(ptr1);
    }
}

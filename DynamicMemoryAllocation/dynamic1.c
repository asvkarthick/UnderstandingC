#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *ptr = NULL;

    printf("Ptr = %p\n", ptr);
    ptr = (char*) malloc(100);
    printf("Ptr = %p\n", ptr);

    free(ptr);
}

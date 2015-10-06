#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *a;
    char *b;
    int i;

    a = (char*)malloc(10);
    b = a;

    for(i = 0; i < 10; i++)
        *(a + i) = i * 10;

    for(i = 0; i < 10; i++)
        b[10 - i - 1] = a[i];

    for(i = 0; i < 10; i++)
        printf("%d, ", b[i]);

    printf("\n");
    free(b);
}

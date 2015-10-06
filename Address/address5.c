#include <stdio.h>

int main(void)
{
    int a[2][2];
    short b[2][2];
    char c[2][2];
    int i, j;

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            printf("Address of a[%d][%d] = %p\n", i, j, &a[i][j]);
    printf("\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            printf("Address of b[%d][%d] = %p\n", i, j, &b[i][j]);
    printf("\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            printf("Address of c[%d][%d] = %p\n", i, j, &c[i][j]);
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 5x6 matrix
#define M 5
#define N 6

void main()
{
    int **a;
    int i, j;

    // Allocate memory for 5 rows to store the addresses
    a = (int**) malloc(M * sizeof(int*));

    for(i = 0; i < M; i++)
        a[i] = (int*) malloc(N * sizeof(int));

    for(i = 0; i < M; i++)
        printf("A[%d] = %p\n", i, a[i]);

    printf("\n\n\n");
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            printf("A[%d][%d] = %p\n", i, j, &a[i][j]);

    for(i = 0; i < M; i++)
        free(a[i]);
    free(a);
}

#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 6

void main()
{
    int **a;
    int i, j;

    a = (int**) malloc(M * sizeof(int*));

    a[0] = (int*) malloc(N * sizeof(int) * M);

    for(i = 1; i < M; i++)
        a[i] = a[i - 1] + N;

    for(i = 0; i < M; i++)
        printf("A[%d] = %p\n", i, a[i]);

    printf("\n\n\n");
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            printf("A[%d][%d] = %p\n", i, j, &a[i][j]);

    free(a[0]);
    free(a);
}

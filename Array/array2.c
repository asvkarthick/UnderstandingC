#include <stdio.h>

int main(void)
{
    int a[] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 1, 1, 4, 5, 5};
    int b[15], c[15], i, n, j, k;

    n = sizeof(a) / sizeof(int);

    b[0] = a[0];
    c[0] = 1;
    j = 1;

    for(i = 1; i < n; i++)
    {
        printf("*************************************************\n");
        printf("Comparing a[%d] = %d with a[%d] = %d, i = %d\n", i, a[i], i - 1, a[i - 1], i);
        if(a[i] != a[i - 1])
        {
            b[j++] = a[i];
            c[i] = 1;
        }
        else
        {
            c[i] = 0;
        }
        printf("Array B contents = \n");
        for(k = 0; k < j; k++)
        {
            printf("%d, ", b[k]);
        }
        printf("\n");

        printf("Array C contents = \n");
        for(k = 0; k <= i; k++)
            printf("%d, ", c[k]);
        printf("\n");
    }

    printf("Contents of Array A = \n");
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("Contents of Array B = \n");
    for(i = 0; i < j; i++)
        printf("%d\n", b[i]);


    printf("Contents of Array C = \n");
    for(i = 0; i < n; i++)
        printf("%d\n", c[i]);

    return 0;
}

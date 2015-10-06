#include <stdio.h>

int main(void)
{
    int a[] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 1, 1, 4, 5, 5};
    int b[15], c[15], i, n, j;

    n = sizeof(a) / sizeof(int);

    b[0] = a[0];
    c[0] = 1;
    j = 1;

    for(i = 1; i < n; i++)
    {
        c[i] = (a[i] != a[i - 1]) ? 1 : 0;

        if(c[i] == 1)
            b[j++] = a[i];
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

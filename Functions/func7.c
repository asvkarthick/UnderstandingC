#include <stdio.h>

// Function prototype declaration
int biggest(int arr[], int n);

void main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 8, 10, 11, 12, 0, 1, 12, 2, 3};
    int c[] = {-1, -2, -3, -4, -5};

    printf("Biggest of A = %d\n", biggest(a, sizeof(a) / sizeof(int)));
    printf("Biggest of B = %d\n", biggest(b, sizeof(b) / sizeof(int)));
    printf("Biggest of C = %d\n", biggest(c, sizeof(c) / sizeof(int)));
}

// Function definition
int biggest(int arr[], int n)
{
    int i, big = arr[0];
    for(i = 1; i < n; i++)
        if(arr[i] > big)
            big = arr[i];
    return big;
}

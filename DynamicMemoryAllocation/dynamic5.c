#include <stdio.h>
#include <stdlib.h>

// Program to find the smallest of N numbers using dynamic memory allocation
void main()
{
    int *arr;
    int n, i, small;

    // Get the value of n
    printf("Enter n : ");
    scanf("%d", &n);

    // Allocate memory
    arr = (int*) malloc(n * sizeof(int));

    printf("Enter %d numbers :\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    small = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] < small)
            small = arr[i];
    }
    printf("Smallest number = %d\n", small);

    // Deallocate memory
    free(arr);
}

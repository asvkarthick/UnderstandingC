#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char *arr[3];

    arr[0] = (char*) malloc(10);
    arr[1] = (char*) malloc(8);
    arr[2] = (char*) malloc(9);

    strcpy(arr[0], "Karthick");
    strcpy(arr[1], "Rashila");
    strcpy(arr[2], "Deepika");

    printf("arr[0] = %s\narr[1] = %s\narr[2] = %s\n", arr[0], arr[1], arr[2]);

    free(arr[0]);
    free(arr[1]);
    free(arr[2]);
}

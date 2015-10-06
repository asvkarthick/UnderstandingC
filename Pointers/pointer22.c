#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 4

void main()
{
    char **strArr;
    strArr = (char**) malloc(M * sizeof(char*));

    strArr[0] = (char*) malloc(10);
    strArr[1] = (char*) malloc(8);
    strArr[2] = (char*) malloc(9);

    strcpy(strArr[0], "Karthick");
    strcpy(strArr[1], "Rashila");
    strcpy(strArr[2], "Deepika");

    printf("strArr[0] = %s\n", strArr[0]);
    printf("strArr[1] = %s\n", strArr[1]);
    printf("strArr[2] = %s\n", strArr[2]);

    free(strArr[0]);
    free(strArr[1]);
    free(strArr[2]);
    free(strArr);
}

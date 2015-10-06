#include<stdio.h>


int main(void)
{
    char *cptr;
    short *sptr;
    int *iptr;
    float *fptr;
    double *dptr;
    void *vptr;

    printf("Size of cptr = %d\n", sizeof(cptr));
    printf("Size of sptr = %d\n", sizeof(sptr));
    printf("Size of iptr = %d\n", sizeof(iptr));
    printf("Size of fptr = %d\n", sizeof(fptr));
    printf("Size of dptr = %d\n", sizeof(dptr));
    printf("Size of vptr = %d\n", sizeof(vptr));

    return 0;
}

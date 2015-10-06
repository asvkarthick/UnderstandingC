#include <stdio.h>

int binarysearch(int *a, int num, int low, int high)
{
    int mid;

    if(low > high) return -1;
    mid = (low + high) / 2;

    if(a[mid] == num) return mid;

    if(a[mid] < num)
        return binarysearch(a, num, mid+1, high);
    if(a[mid] > num)
        return binarysearch(a, num, low, mid-1);
}

void main()
{
    int a[] = {10, 12, 20, 23, 29, 30, 43, 46, 47, 49, 52, 55, 60, 65, 75};

    printf("Number 30 is positioned at %d\n", binarysearch(a, 31, 0, 14));
}

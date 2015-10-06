#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("file1.txt", "w");
    if(fp == NULL)
    {
        printf("Error: File not opening\n");
        return -1;
    }
    fprintf(fp, "This is the first file write program\n");
    fclose(fp);
}

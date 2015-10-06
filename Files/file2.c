#include <stdio.h>

int main()
{
    FILE *fp;
    char str[100];
    fp = fopen("one.txt", "r");
    if(fp == NULL)
    {
        printf("Error: Opening file\n");
        return -1;
    }
    fgets(str, 100, fp);
    printf("String = %s\n", str);
    fclose(fp);
    return 0;
}

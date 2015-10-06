#include <stdio.h>

void main()
{
    char str[100];
    fscanf(stdin, "%s", str);
    fprintf(stdout, "Entered string = %s\n", str);
}

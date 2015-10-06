#include <stdio.h>

void main()
{
    int num = 0;
    char *str = "12345", *p;

    p = str;
    while(*p != '\0')
    {
        num = num * 10 + *p - '0';
        p++;
    }
    printf("Num = %d\n", num);
    num = 0;
    printf("Num = %d\n", num);
    num = atoi(str);
    printf("Num = %d\n", num);
}

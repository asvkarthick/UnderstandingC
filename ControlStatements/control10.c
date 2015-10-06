#include <stdio.h>

int main(void)
{
    char ch = 'R';

    if((ch >= '0') && (ch <= '9'))
        printf("Numeric.\n");
    else if((ch >= 'A') && (ch <= 'Z'))
        printf("Big alphabets\n");
    else if((ch >= 'a') && (ch <= 'z'))
        printf("Small alphabets\n");
    else
        printf("Other characters\n");

    return 0;
}

#include <stdio.h>

int main(void)
{
    char ch = '0';

    if((ch >= 48) && (ch <= 57))
        printf("Numeric.\n");
    else if((ch >= 65) && (ch <= 90))
        printf("Big alphabets\n");
    else if((ch >= 97) && (ch <= 122))
        printf("Small alphabets\n");
    else
        printf("Other characters\n");

    return 0;
}

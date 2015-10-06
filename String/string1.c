#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[100] = "Karthick Kumaran";
    char b[100];
    char c[100];

    strcpy(b, a);

    printf("A = %s\n", a);
    printf("B = %s\n", b);

    strncpy(c, a, 5);
    c[5] = '\0';

    printf("A = %s\n", a);
    printf("B = %s\n", b);
    printf("C = %s\n", c);

    return 0;
}

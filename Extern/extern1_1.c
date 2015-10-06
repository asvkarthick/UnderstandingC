#include <stdio.h>

// Global variable
int a = 10;
extern int b;

int main(void)
{
    printf("A = %d\n", a);
    printf("B = %d\n", b);

    return 0;
}

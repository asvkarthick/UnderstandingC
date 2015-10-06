#include <stdio.h>

int main(void)
{
    int a = 100;

    printf("A = %d\n", a);

    {
        int a = 20;
        printf("A = %d\n", a);
    }

    printf("A = %d\n", a);

    return 0;
}

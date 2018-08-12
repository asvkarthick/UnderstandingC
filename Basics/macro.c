#include <stdio.h>

#define NUM 6 // NUM Macro
#define max(a,b) (((a) > (b)) ? (a) : (b))

int main()
{
    int product;
    int a, b;

    product = NUM * NUM;

    printf("Product = %d\n", product);

    printf("Max = %d\n", max(5 + 6, 7 + 12));

    a = 5;
    b = 6;
    a = max(a++, b++);

    printf("a = %d,b = %d\n", a, b);

    return 0;
}

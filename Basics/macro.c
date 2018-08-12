#include <stdio.h>

#define NUM 6 // NUM Macro
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define square(x) x * x
#define concat(x,y) x##y

int main()
{
    int product;
    int a, b;
    int ab;

    product = NUM * NUM;

    printf("Product = %d\n", product);

    printf("Max = %d\n", max(5 + 6, 7 + 12));

    a = 5;
    b = 6;
    a = max(a++, b++);

    printf("a = %d,b = %d\n", a, b);
    b = square(b + 1);
    printf("Square of b = %d\n", b);
    b = square((b + 1));
    printf("Square of b = %d\n", b);

    concat(a, b) = 100;
    printf("ab = %d\n", ab);

    return 0;
}

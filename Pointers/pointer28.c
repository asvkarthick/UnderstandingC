#include <stdio.h>

void main()
{
    int p = 25;
    int *p1 = &p;
    int *p21 = &p1;
    int **p22 = &p1;
    
    printf("P     = %d\n", p);
    printf("&p    = %p\n", &p);
    printf("p1    = %p\n", p1);
    printf("&p1   = %p\n", &p1);
    printf("p21   = %p\n", p21);
    printf("p22   = %p\n", p22);
    printf("*p21  = %x\n", *p21);
    printf("*p22  = %x\n", *p22);
    printf("**p22 = %x\n", **p22);
}

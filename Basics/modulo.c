#include <stdio.h>

int main(void)
{
   int a = 2, b = -2, c = 1, d = -1, e = 3;

   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("c = %d\n", c);
   printf("d = %d\n", d);
   printf("e = %d\n", e);

   printf("a mod e = %d\n", a % e);
   printf("b mod e = %d\n", b % e);
   printf("c mod e = %d\n", c % e);
   printf("d mod e = %d\n", d % e);

   return 0;
}

#include<stdio.h>

union
{
   short a;
    
   struct
   {
       unsigned short a:8;
       unsigned short b:8;
   }s;
}u;

int main(void)
{
    u.a = 0x78ff;
    printf("size of u = %d\n", sizeof(u));
    printf("U.A = %08x\n", u.a);
    printf("U.S.A = %08x\n", u.s.a);
    printf("U.S.B = %08x\n", u.s.b);    
    return 0;
}

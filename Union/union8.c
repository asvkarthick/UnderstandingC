#include<stdio.h>

union
{
   short a;
    
   struct
   {
       char a;
       char b;
       char c;
   }s;
}u;

int main(void)
{
    printf("%x,%x,%x,%x\n", u.a,u.s.a,u.s.b,u.s.c);
    u.a = 0x1234;
    printf("%x,%x,%x,%x\n", u.a,u.s.a,u.s.b,u.s.c);
    u.s.c = u.s.a;
    u.s.a = u.s.b;
    printf("%x,%x.%x,%x\n", u.a,u.s.a,u.s.b,u.s.c);
    u.s.b = u.s.c;
    printf("%x,%x,%x,%x\n", u.a,u.s.a,u.s.b,u.s.c);
   
    return 0;
}

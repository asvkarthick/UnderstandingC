#include<stdio.h>

/* There are two types of arguments
 * 1 - Actual Arguments (Arguments that are used in the function calls)
 * 2 - Formal Arguments (Arguments that are used in the function definitions)
 */

// Function prototype declaration
int sum(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int mod(int a,int b);

void main()
{
    int xa=5,xb=2,s1,s2,m,d,m1;

    // Function calls
    // xa & xb are actual arguments
    s1=sum(xa,xb);
    s2=sub(xa,xb);
    m=mul(xa,xb);
    d=div(xa,xb);
    m1=mod(xa,xb);

    printf(" %d %d %d %d %d \n", s1,s2,m,d,m1);
}

// Function definitions
// a & b are formal arguments
int sum(int a, int b)
{
    return a + b;
}


int sub(int a, int b)
{
    int s2=a-b;
    return s2;
}


int mul(int a, int b)
{
    int m=a*b;
    return m;
}


int div(int a, int b)
{
    int d=a/b;
    return d;
}

int mod(int a, int b)
{
    int m1=a%b;
    return m1;
}


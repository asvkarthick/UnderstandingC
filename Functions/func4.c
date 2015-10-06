#include<stdio.h>

int sum(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int mod(int,int);

void main()
{
    int a=5,b=2,s1,s2,m,d,m1;
    s1=sum(a,b);
    s2=sub(a,b);
    m=mul(a,b);
    d=div(a,b);
    m1=mod(a,b);
    printf(" %d %d %d %d %d \n", s1,s2,m,d,m1);
}

int sum(int a, int b)
{
    int s1=a+b;
    return s1;
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


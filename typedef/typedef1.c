#include <stdio.h>

struct str
{
    int a;
    int b;
    int c;
};

typedef unsigned int uint;
typedef signed int sint;
typedef char byte;
typedef struct str stru;

void main()
{
    uint u;
    sint s;
    byte b;
    stru st;

    printf("Size of u  = %d\n", sizeof(u));
    printf("Size of s  = %d\n", sizeof(s));
    printf("Size of b  = %d\n", sizeof(b));
    printf("Size of st = %d\n", sizeof(st));
}

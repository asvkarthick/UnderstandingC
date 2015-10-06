#include <stdio.h>

struct str
{
    int a;
    int b;
    int c;
};

typedef unsigned int uint;
typedef signed int sint;
typedef unsigned char byte;
typedef struct str stru;

void main()
{
    uint u;
    sint s;
    byte b;
    stru st;

    u = 1 << 31;
    s = 1 << 31;
    b = 1 << 7;
    st.a = 100;
    st.b = 200;
    st.c = 300;

    printf("U = %x, S = %x, B = %x\n", u, s, b);
    printf("A = %d, B = %d, C = %d\n", st.a, st.b, st.c);
}

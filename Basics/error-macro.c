#include <stdio.h>

/*
    Use the below command to trigger the compiler error
    gcc error-macro.c -DDEBUG
*/

#ifdef DEBUG
#error "DEBUG IS DEFINED"
#endif

int main()
{
    printf("Demonstrating #error\n");
    return 0;
}

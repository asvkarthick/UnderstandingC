#include <stdio.h>

extern int externvar;
extern void extern_func();

int main()
{
    printf("%d\n", externvar);
    extern_func();

    return 0;
}

#include <stdio.h>

int externvar = 10;

void extern_func()
{
    printf("Extern var = %d\n", externvar);
}

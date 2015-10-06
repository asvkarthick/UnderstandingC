#include <stdio.h>

void link1_func();
void link2_func();
void link3_func();

void main()
{
    link1_func();
    link2_func();
    link3_func();
    printf("%s %d %s\n", __func__, __LINE__, __FILE__);
}

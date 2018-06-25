#include <stdio.h>

struct str
{
    char a;
    char *b;
};

int main(void)
{
    printf("Size of structure = %ld\n", sizeof(struct str));
    return 0;
}

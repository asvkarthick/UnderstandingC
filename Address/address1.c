#include <stdio.h>

// Printing the address of a variable
// Note down the address remains same amount of bits irrespective of the datatype of the variable

int main(void)
{
    int i;

    printf("Address of i = %p\n", &i);
}

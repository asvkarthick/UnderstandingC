#include <stdio.h>

// Function func() cannot be called from other file
static void func()
{
    printf("Static function\n");
}

// Global variable 'a' cannot be accessed from other file
static int a = 20;

void main()
{
    func();
    printf("A = %d\n", a);

    {
        static int a = 10;
        printf("A = %d\n", a);
    }

    printf("A = %d\n", a);
    func2();
}

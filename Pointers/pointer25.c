#include <stdio.h>

void main(int argc, char *argv[])
{
    int num1, num2;
    if(argc < 4)
    {
        printf("Error: %s num1 op num2\n", argv[0]);
        return;
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    if(argv[2][0] == '+')
        printf("%d\n", num1 + num2);
    else if(argv[2][0] == '-')
        printf("%d\n", num1 - num2);
    else if(argv[2][0] == '$')
        printf("%d\n", num1 * num2);
    else if(argv[2][0] == '/')
        printf("%d\n", num1 / num2);
    else if(argv[2][0] == '%')
        printf("%d\n", num1 % num2);
}

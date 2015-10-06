#include <stdio.h>

int main(void)
{
    int parcount = 0, count = 0, i;
    char c, expr[100];

    printf("Enter the expression: ");
    scanf("%s", expr);

    for(i = 0; (c = expr[i]) != '\0'; i++)
    {
        if(c == '(')
        {
            ++parcount;
            ++count;
        }
        else if(c == ')')
            --count;
        if(count < 0)
            printf("Invalid expression!!!\n");
    }
    printf("Number of paired parantheses = %d\n", parcount);

    return 0;
}

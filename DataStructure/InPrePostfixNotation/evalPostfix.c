#include <stdio.h>

#define N 100

double evaluatePostfix(char*);

struct stack
{
    double items[N];
    int top;
} s;

void push(double d)
{
    s.items[++s.top] = d;
}

double pop()
{
    if(s.top == -1)
    {
        printf("Stack underflow!!!\n");
        return -1.0;
    }
    return s.items[s.top--];
}

int main(void)
{
    char expr[N];
    double ans;

    printf("Enter the expression : ");
    scanf("%s", expr);

    ans = evaluatePostfix(expr);
    printf("Answer = %f\n", ans);

    return 0;
}

double evaluatePostfix(char *expr)
{
    int i;
    double op1, op2;

    s.top = -1;

    for(i = 0; expr[i] != '\0'; i++)
    {
        if(expr[i] >= '0' && expr[i] <= '9') // Operand
            push((double)(expr[i] - '0'));
        else
        {
            op2 = pop();
            op1 = pop();
            switch(expr[i])
            {
                case '+': push(op1 + op2);
                          break;
                case '-': push(op1 - op2);
                          break;
                case '*': push(op1 * op2);
                          break;
                case '/': push(op1 / op2);
                          break;
            }
        }
    }
    return pop();
}

#include <stdio.h>

// Number of elements in stack
#define N 4

// Define the stack
int stack[N];
int top = -1;

int isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if(top == N - 1)
        return 1;
    return 0;
}

void push(int data)
{
    top++;
    stack[top] = data;
}

int pop()
{
    return stack[top--];
}

void displayStack()
{
    int i = 0;
    while(i <= top)
    {
        if(i == top)
            printf("top ->\t");
        else
            printf("\t");
        printf("%d\n", stack[i]);
        i++;
    }
}

int main(void)
{
    int op, data;

    do
    {
        printf("Stack operations . . .\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY STACK\n");
        printf("0.EXIT\n");
        printf("Enter the operation that you want to perform : ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                if(isFull())
                {
                    printf("Stack Full *********\n");
                }
                else
                {
                    printf("Enter the element to push : ");
                    scanf("%d", &data);
                    // Call function to push the data
                    push(data);
                }
                break;
            case 2:
                if(isEmpty())
                {
                    printf("Stack is Empty #########\n");
                }
                else
                {
                    // Call function to pop the data
                    printf("Popped element = %d\n", pop());
                }
                break;
            case 3:
                if(isEmpty())
                    printf("Stack is Empty %%%%%%%%%%\n");
                // Call function to display the stack
                displayStack();
                break;
            case 0:
                break;
        }
    } while(op != 0);

    return 0;
}

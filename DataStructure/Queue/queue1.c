#include <stdio.h>

// Number of elements in the queue
#define N 4

// Define the queue
int queue[N];

int front = -1, rear = -1;

int isFull()
{
    if(rear == N - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

void insert()
{
    int data;
    if(!isFull())
    {
        printf("Enter the data to insert : ");
        scanf("%d", &data);
        queue[++rear] = data;
        if(rear == 0) front = 0;
    }
    else
    {
        printf("Queue Full *****\n");
    }
}

int removee()
{
    int data = -1;
    if(isEmpty())
    {
        printf("Queue Empty #####\n");
    }
    else
    {
        data = queue[front++];
        if(front == rear + 1)
            front = rear = -1;
    }
    return data;
}

void display()
{
    int i;

    if(isEmpty())
    {
        printf("Queue Empty ^^^^^\n");
        return;
    }
    for(i = front; i <= rear; i++)
    {
        if(i == front)
            printf("Front ->");
        else
            printf("        ");
        printf("\t%d", queue[i]);
        if(i == rear)
            printf("\t<- rear");
        printf("\n");
    }
}

int main(void)
{
    int op, data;

    do
    {
        printf("***** Queue operations *****\n");
        printf("1. INSERT\n");
        printf("2. REMOVE\n");
        printf("3. DISPLAY QUEUE\n");
        printf("4. NUM ELEMENTS IN QUEUE\n");
        printf("0. EXIT\n");
        printf("Enter the operation to perform : ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                // Call the function to insert the data
                insert();
                break;
            case 2:
                // Call the function to remove the data
                data = removee();
                if(data == -1)
                    printf("Queue Empty . . . . .\n");
                else
                    printf("Data = %d\n", data);
                break;
            case 3:
                // Call the function to display the queue contents
                display();
                break;
            case 4:
                printf("Number of elements that can be stored in queue = %d\n", N);
                break;
            case 0:
                break;
        }
    } while(op != 0);

    return 0;
}

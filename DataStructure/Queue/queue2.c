#include <stdio.h>

// Circular queue

// Number of elements in the queue
#define N 4

// Define the queue
int queue[N];

int front = 0, rear = 0, count = 0;

int isFull()
{
    if(count >= N)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(count == 0)
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
        queue[rear] = data;
        rear = (rear + 1) % N;
        count++;
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
        data = queue[front];
        front = (front + 1) % N;
        count--;
        if(count == 0)
            front = rear = 0;
    }
    return data;
}

void display()
{
    int i = count, j = 0;

    if(isEmpty())
    {
        printf("Queue Empty ^^^^^\n");
        return;
    }
    while(i--)
    {
#if 0
        if(i == front)
            printf("Front ->");
        else
            printf("        ");
        printf("\t%d", queue[i]);
        if(i == rear)
            printf("\t<- rear");
        printf("\n");
#endif
        printf("%d\n", queue[(front + j) % N]);
        j++;
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

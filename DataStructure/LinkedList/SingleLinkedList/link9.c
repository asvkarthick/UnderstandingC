#include <stdio.h>
#include <stdlib.h>
#define N 4
// define the stack
int stack[N];
int top = N;

struct node
{
    int data;
    struct node *next;
};

struct node *HEAD = NULL;

struct node* getNode()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    return temp;
}

void display()
{
    struct node *currNode = HEAD;
    if(HEAD == NULL)
        printf("\n\n\n***** LIST EMPTY *****\n\n\n");
    while(currNode != NULL)
    {
        if(currNode == HEAD)
            printf("TOP --->   ");
        else
            printf("           ");
        printf("%d\n", currNode->data);
        currNode = currNode->next;
    }
}

void insertAtFirst()
{
    int data;
    struct node *p;

    printf("Enter the element to insert : ");
    scanf("%d", &data);
    p = getNode();
    p->data = data;
    p->next = HEAD;
    HEAD = p;
}

void deleteAtFirst()
{
    struct node *currNode = HEAD;

    if(currNode == NULL)
    {
        printf("List Empty #####\n");
        return;
    }
    HEAD = currNode->next;
    free(currNode);
}



int main(void)
{
    HEAD = NULL;
    int op;
    do
    {
        printf("Stack operation Using SingleLinked List..\n");
        printf("1.DISPLAY\n");
        printf("2.POP\n");
        printf("3.PUSH\n");
        printf("0.EXIT\n");
        printf("Enter the operation to perform : ");
        scanf("%d", &op); 
        switch(op)
	{
            case 1: display();
                    break;
            case 2: deleteAtFirst();
                    break;
            case 3: insertAtFirst();
                    break;
            case 0:
                    break;
	}
    
    }while(op !=0);

    return 0;
}

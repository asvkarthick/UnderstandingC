#include <stdio.h>
#include <stdlib.h>

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
        printf("%d", currNode->data);
        if(currNode->next != NULL)
            printf(" -> ");
        else
            printf("\n");
        currNode = currNode->next;
    }
}

void insertAtEnd()
{
    int data;
    struct node *p, *currNode;
    printf("Enter the element to insert : ");
    scanf("%d", &data);
    p = getNode();
    p->data = data;
    p->next = NULL;

    if(HEAD == NULL)
    {
        HEAD = p;
    }
    else
    {
        currNode = HEAD;
        while(currNode->next != NULL)
            currNode = currNode->next;
        currNode->next = p;
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

void deleteAtEnd()
{
    struct node *currNode, *prevNode;

    currNode = prevNode = HEAD;

    if(currNode == NULL)
    {
        printf("List Empty *****\n");
        return;
    }

    while(currNode->next != NULL)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = NULL;
    if(currNode == HEAD) HEAD = NULL;
    free(currNode);
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

void insertAfter()
{
    int data;
    struct node *curr, *next, *prev;

    printf("Enter the data after to insert : ");
    scanf("%d", &data);

    curr = HEAD;
    while(curr != NULL)
    {
        if(curr->data == data)
            break;
        curr = curr->next;
    }

    printf("Enter the data to insert : ");
    scanf("%d", &data);

    prev = curr;
    next = curr->next;
    
    curr = getNode();
    curr->data = data;
    curr->next = next;
    prev->next = curr;
}

void deleteSpecific()
{
    int data;
    struct node *curr, *prev;

    printf("Enter the data to delete : ");
    scanf("%d", &data);

    curr = prev = HEAD;

    while(curr != NULL)
    {
        if(curr->data == data)
        {
            prev->next = curr->next;
            if(HEAD == curr) HEAD = curr->next; // HEAD = HEAD->next;
            free(curr);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void reverseList()
{
    struct node *prev, *curr, *next;

    prev = NULL;
    curr = HEAD;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    HEAD = prev;
}

void deleteAll()
{
    struct node *n = HEAD, *tmp;

    while(n != NULL)
    {
        tmp = n->next;
        free(n);
        n = tmp;
    }
    HEAD = NULL;
}

void insertAscending()
{
    int data;
    struct node *n, *prev, *curr;
    printf("Enter the data to insert : ");
    scanf("%d", &data);

    n = getNode();
    n->data = data;
    n->next = NULL;

    // If there is no node in the list, this is the first node
    if(HEAD == NULL)
    {
        HEAD = n;
        return;
    }
    else
    {
        prev = NULL;
        curr = HEAD;
        while((curr != NULL) && (curr->data < data))
        {
            prev = curr;
            curr = curr->next;
        }
        // If the node that we are going to insert happen to be the last node
        if(curr == NULL)
        {
            prev->next = n;
            return;
        }
        else if(prev == NULL) // If the node that we are going to insert happen to be the first node
        {
            n->next = curr;
            HEAD = n;
        }
        else
        {
            prev->next = n;
            n->next = curr;
        }
    }
}

int main(void)
{
    HEAD = NULL;
    int op;
    do
    {
        printf("Linked List Operations..\n");
        printf("1.INSERT\n");
        printf("2.DELETE AT END\n");
        printf("3.DISPLAY\n");
        printf("4.DELETE AT FIRST\n");
        printf("5.INSERT AT FIRST\n");
        printf("6.INSERT AFTER\n");
        printf("7.DELETE SPECIFIC\n");
        printf("8.REVERSE LIST\n");
        printf("9.DELETE ALL\n");
        printf("10.INSERT ASCENDING\n");
        printf("0.EXIT\n");
        printf("Enter the operation to perform : ");
        scanf("%d", &op); 
        switch(op)
	{
            case 1: insertAtEnd();
                    break;
            case 2: deleteAtEnd();
                    break;
            case 3: display();
                    break;
            case 4: deleteAtFirst();
                    break;
            case 5: insertAtFirst();
                    break;
            case 6: insertAfter();
                    break;
            case 7: deleteSpecific();
                    break;
            case 8: reverseList();
                    break;
            case 9: deleteAll();
                    break;
            case 10: insertAscending();
                     break;
            case 0: deleteAll();
                    break;
	}
    
    }while(op !=0);

    return 0;
}

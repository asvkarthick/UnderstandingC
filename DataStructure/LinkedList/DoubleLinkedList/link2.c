#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
            printf(" <-> ");
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
    p->prev = NULL;

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
        p->prev = currNode;
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
    HEAD->prev = p;
    p->prev = NULL;
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
    if(HEAD != NULL) HEAD->prev = NULL;
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
    next->prev = curr;
    curr->prev = prev;
}

void deleteSpecific()
{
    int data;
    struct node *curr, *prev, *next;

    printf("Enter the data to delete : ");
    scanf("%d", &data);

    curr = prev = HEAD;

    while(curr != NULL)
    {
        if(curr->data == data)
        {
            prev->next = curr->next;
            next = curr->next;
            if(next != NULL) next->prev = prev;
            if(HEAD == curr)
            {
                HEAD = curr->next; // HEAD = HEAD->next;
                if(HEAD != NULL) HEAD->prev = NULL;
            }
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
    struct node *prev, *curr, *tmp;

    prev = NULL;
    curr = HEAD;

    while(curr != NULL)
    {
        tmp = curr->next;
        curr->next = curr->prev;
        curr->prev = tmp;
        prev = curr;
        curr = tmp;
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
    struct node *n,*prev,*curr;
    printf("Enter the data to insert:");
    scanf("%d",&data);
    
    n=getNode();
    n->data=data;
    n->next=NULL;
    n->prev=NULL;

    curr=HEAD; prev=NULL;
    while((curr!=NULL) && (curr->data < data))
    {
        prev=curr; curr=curr->next;
    }
    if(prev==NULL)
    {
        n->next=curr;
        if(curr) curr->prev=n;
        HEAD=n;
    }
    else if(curr==NULL)
    {
        prev->next=n;
        n->prev=prev;
    }
    else
    {
        prev->next=n;
        curr->prev=n;
        n->prev=prev;
        n->next=curr;
    }
}

void insertdescending()
{
    int data;
    struct node *n,*prev,*curr;
    printf("Enter the data to insert:");
    scanf("%d",&data);
    
    n=getNode();
    n->data=data;
    n->next=NULL;
    n->prev=NULL;

    curr=HEAD; prev=NULL;
    while((curr!=NULL) && (curr->data > data))
    {
        prev=curr; curr=curr->next;
    }
    if(prev==NULL)
    {
        n->next=curr;
        if(curr) curr->prev=n;
        HEAD=n;
    }
    else if(curr==NULL)
    {
        prev->next=n;
        n->prev=prev;
    }
    else
    {
        prev->next=n;
        curr->prev=n;
        n->prev=prev;
        n->next=curr;
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
        printf("11.INSERT DESCENDING\n");
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
            case 11:insertdescending();
                    break;
            case 0: deleteAll();
                    break;
	}
    
    }while(op !=0);

    return 0;
}

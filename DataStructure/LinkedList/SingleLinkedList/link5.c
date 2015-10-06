#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *n)
{
    while(n != NULL)
    {
        printf("%d ", n->data);
        if(n->next) printf("-> ");
        n = n->next;
    }
    printf("\n");
}

int main(void)
{
    int array[] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0};
    struct node *head;
    int i;

    head = (struct node*) &array[0];
    head->next = (struct node*) &array[2];
    head->next->next = (struct node*) &array[4];
    head->next->next->next = (struct node*) &array[8];

    head->data = 20;
    head->next->data = 25;
    head->next->next->data = 30;
    head->next->next->next->data = 35;
    head->next->next->next->next = NULL;
    

    display(head);

    for(i = 0; i < 10; i++)
        printf("%x\n", array[i]);

    return 0;
}

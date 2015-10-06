#include <stdio.h>
#include <string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node *n)
{
    while(n != NULL)
    {
        printf("%d ", n->data);
        if(n->next) printf(" <->");
        n = n->next;
    }
}

void main()
{
    int array[10][3], i;
    struct node *head;

    memset(array, 0, sizeof(array));

    for(i = 0; i < 9; i++)
    {
        array[i + 1][0] = (int)&array[i];
        array[i    ][2] = (int)&array[i + 1];
        array[i    ][1] = 10 + i * 5 + 2 * (i + 3);
    }

    head = (struct node*) &array[0][0];

    display(head);

    for(i = 0; i < 10; i++)
        printf("%x, %x, %x\n", array[i][0], array[i][1], array[i][2]);
    for(i = 0; i < 10; i++)
        printf("%d, %d, %d\n", array[i][0], array[i][1], array[i][2]);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data 
{
    int serialno;
    int age;
    int salary;
    int idno;
    char name[100];
    char degree[100];
};

struct node
{
    struct data d;
    struct node *next;
};

struct node *HEAD = NULL;

struct node* getNode()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    return temp;
}

void print(struct node *curr)
{
    printf("Serial No: %d\n", (curr->d.serialno));
    printf("Name     : %s\n", (curr->d.name));
    printf("Age      : %d\n", (curr->d.age));
    printf("Degree   : %s\n", (curr->d.degree));
    printf("Salary   : %d\n", (curr->d.salary));
    printf("ID number: %d\n", (curr->d.idno));
}

int noofnodes()
{
    struct node *curr;
    curr = HEAD;
    int count =0;
    if( curr == NULL) return 0;
    else
    {
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
}

void insertAtEnd()
{
    struct node *p, *curr;
    struct data d;
    int s;
    
    p = getNode();
    p->d = d;
    p->next = NULL;
    
    s = noofnodes();
    p->d.serialno = s+1;
    
    printf("Enter Name : ");
    scanf("%s", p->d.name);
    printf("Enter ID No : ");
    scanf("%d", &p->d.idno);
    printf("Enter salary : ");
    scanf("%d", &p->d.salary);
    printf("Enter Age : ");
    scanf("%d", &p->d.age);
    printf("Enter degree : ");
    scanf("%s", p->d.degree);
    

    if(HEAD == NULL)
    {
        HEAD = p;
    }
    else
    {
        curr = HEAD;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = p;
    }
}



void delete()
{
    struct node *curr, *prev;
    int s;
    curr = HEAD;prev = NULL;

    printf("Enter the serial no of node to delete:");
    scanf("%d",&s);
   
    while(curr != NULL)
    {
        if(curr->d.serialno == s)
            break;
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if(prev == NULL)
    {
        HEAD = curr->next;
        free(curr);
    }
    else
    {
        prev->next =  curr->next;
        free(curr);
    }

}
void serialnum()
{
    struct node *curr; 
    curr = HEAD;
    int s;
    printf("Enter serial no:");
    scanf("%d",&s);
    while(curr != NULL)
    {
        if(curr->d.serialno == s)
        {
            print(curr);
            break;  
        }
        else
            curr = curr->next;
    }
}

void idno()
{
    struct node *curr; 
    curr = HEAD;
    int id;
    printf("Enter ID no:");
    scanf("%d",&id);
    while(curr != NULL)
    {
        if(curr->d.idno == id)
        {
            print(curr);
            break;  
        }
        else
            curr = curr->next;
    }
}

void degree()
{
    struct node *curr;
    curr = HEAD;
    char deg[100];
    printf("Enter DEGREE:");
    scanf("%s",deg);
    while(curr != NULL)
    {
        if(0==(strcmp(curr->d.degree,deg)))
            print(curr);
        curr = curr->next;
    }
}

void salgrt()
{
    struct node *curr;int sal;
    curr = HEAD;
    printf("Enter Salary:");
    scanf("%d",&sal);
    while(curr != NULL)
    {
        if(curr->d.salary > sal)
            print(curr);
        curr = curr->next;
    }
}

void salless()
{
    struct node *curr;int sal;
    curr = HEAD;
    printf("Enter Age:");
    scanf("%d",&sal);
    while(curr != NULL)
    {
        if(curr->d.salary < sal)
            print(curr);
        curr = curr->next;
    }
}

void salequal()
{
    struct node *curr;int sal;
    curr = HEAD;
    printf("Enter Age:");
    scanf("%d",&sal);
    while(curr != NULL)
    {
        if(curr->d.salary == sal)
            print(curr);
        curr = curr->next;
    }
}

void agegrt()
{
    struct node *curr;int age;
    curr = HEAD;
    printf("Enter Age:");
    scanf("%d",&age);
    while(curr != NULL)
    {
        if(curr->d.age > age)
            print(curr);
        curr = curr->next;
    }
}

void ageless()
{
    struct node *curr;
    curr = HEAD;
    int age;
    printf("Enter Age:");
    scanf("%d",&age);
    while(curr != NULL)
    {
        if(curr->d.age < age)
            print(curr);
        curr = curr->next;
    }
}

void ageequal()
{
    struct node *curr;int age;
    curr = HEAD;
    printf("Enter Age:");
    scanf("%d",&age);
    while(curr != NULL)
    {
        if(curr->d.age == age)
            print(curr);
        curr = curr->next;
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
        printf("3.NO.OF.NODES\n");
        printf("4.ENTER SALARY TO VIEW LIST OF RECORDS GREATER THAN THAT \n");
        printf("5.ENTER SALARY TO VIEW LIST OF RECORDS LESSER THAN THAT\n");
        printf("6.ENTER SALARY TO VIEW LIST OF RECORDS EQUAL TO THAT\n");
        printf("7.ENTER ID NO TO VIEW RECORDS\n");
        printf("8.ENTER SERIAL NO TO VIEW RECORDS\n");
        printf("9.ENTER DEGREE TO VIEW LIST OF RECORDS HAVING SAME DEGREE\n");
        printf("10.ENTER AGE TO VIEW LIST OF RECORDS GREATER THAN THAT \n");
        printf("11.ENTER AGE TO VIEW LIST OF RECORDS LESSER THAN THAT\n");
        printf("12.ENTER AGE TO VIEW LIST OF RECORDS EQUAL TO THAT\n");
        
        printf("0.EXIT\n");
        printf("Enter the operation to perform : ");
        scanf("%d", &op); 
        switch(op)
	{
            case 1: insertAtEnd();
                    break;
            case 2: delete();
                    break;
            case 3: printf("No.of.Nodes = %d\n", noofnodes());
                    break;
            case 4: salgrt();
                    break;
            case 5: salless();
                    break;
            case 6: salequal();
                    break;
            case 7: idno();
                    break;
            case 8: serialnum();
                    break;
            case 9: degree();
                    break;
            case 10: agegrt();
                     break; 
            case 11: ageless();
                     break;
            case 12: ageequal();
                     break;
            case 0:  break;
	}
    
    }while(op !=0);

    return 0;
}

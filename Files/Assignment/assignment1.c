#include <stdio.h>

struct record
{
    char name[100];
    int age;
    int salary;
    int savings;
    int loan;
};

typedef struct record Record;

int main(int argc, char *argv[])
{
    Record r;
    int n, i;
    FILE *fo;

    if((fo = fopen(argv[1], "w")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }

    printf("Enter the number of values to store : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter name-%d    : ", i);
        scanf("%s", r.name);
        printf("Enter age-%d     : ", i);
        scanf("%d", &r.age);
        printf("Enter Salary-%d  : ", i);
        scanf("%d", &r.salary);
        printf("Enter savings-%d : ", i);
        scanf("%d", &r.savings);
        printf("Enter loan-%d    : ", i);
        scanf("%d", &r.loan);
        fprintf(fo, "%20s\t%4d\t%8d\t%8d\t%8d\n", r.name, r.age, r.salary, r.savings, r.loan);
    }

    fclose(fo);
    return 0;
}

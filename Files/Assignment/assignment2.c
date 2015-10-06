#include <stdio.h>
#include <string.h>

typedef struct record
{
    char name[100];
    int age;
    int salary;
    int savings;
    int loan;
} Record;

int main(int argc, char *argv[])
{
    Record r;
    FILE *fi;
    int diff;
    char name[100];

    if((fi = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error: Opening file %s\n", argv[1]);
        return -1;
    }

    fscanf(fi, "%s %d %d %d %d", r.name, &r.age, &r.salary, &r.savings, &r.loan);
    printf("%20s\t%4d\t%8d\t%8d\t%8d\n", r.name, r.age, r.salary, r.savings, r.loan);
    diff = r.salary - r.savings - r.loan;
    strcpy(name, r.name);

    while(!feof(fi))
    {
        fscanf(fi, "%s %d %d %d %d", r.name, &r.age, &r.salary, &r.savings, &r.loan);
        printf("%20s\t%4d\t%8d\t%8d\t%8d\n", r.name, r.age, r.salary, r.savings, r.loan);
        if(diff < (r.salary - r.savings - r.loan))
        {
            strcpy(name, r.name);
        }
    }
    printf("%s will enjoy the life as he will have lot of money each month\n", name);

    fclose(fi);
    return 0;
}

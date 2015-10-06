#include <stdio.h>
#include <string.h>

struct str
{
    char name[100];
    int age;
    char gender;
    char graduation[10];
};

void print(struct str st)
{
    printf("Name = %s\n", st.name);
    printf("Age  = %d\n", st.age);
    printf("Sex  = %c\n", st.gender);
    printf("Grad = %s\n", st.graduation);
}

void main()
{
    struct str s;

    printf("Size of structure = %d\n", sizeof(s));

    strcpy(s.name, "Karthick Kumaran");
    s.age = 29;
    s.gender = 'M';
    strcpy(s.graduation, "B.E");

    print(s);
}

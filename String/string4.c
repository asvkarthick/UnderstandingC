#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[5][10] = {"Karthick",
                     "Kumaran",
                     "Rashila",
                     "Deepika",
                     "Sammu"
                    };

    printf("Size of a = %d\n", sizeof(a));
    printf("String a[3][1] = %s\n", &a[3][1]);
    printf("String a[1][2] = %s\n", &a[1][2]);
    a[3][strlen(a[3])] = 'A';
    a[3][strlen(a[3])] = 'S';
    a[3][strlen(a[3])] = 'V';
    printf("String a[3][1] = %s\n", &a[3][1]);
    printf("String a[1][2] = %s\n", &a[1][2]);
    printf("String a[3] = %s\n", a[3]);
}

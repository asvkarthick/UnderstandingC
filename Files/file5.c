#include <stdio.h>

int main()
{
    FILE *fp;
    int sno, i;
    char name[100];
    int n, m1, m2, m3, m4, m5, sum;
    float avg;

    if((fp = fopen("Record.txt", "w")) == NULL)
    {
        printf("Error: Opening Record.txt file\n");
        return -1;
    }

    printf("Enter the value of n : ");
    scanf("%d", &n);

    fprintf(fp, "------------------------------------------------------------------------------\n");
    fprintf(fp, "%s\t%12s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "S.No", "Name", "Mark1", "Mark2", "Mark3", "Mark4", "Mark5", "Total","Avg");
    fprintf(fp, "------------------------------------------------------------------------------\n");
    while(n--)
    {
        printf("Enter details of the student\n");
        printf("Enter serial no : ");
        scanf("%d", &sno);
        printf("Enter name      : ");
        scanf("%s", name);
        printf("Enter mark-1    : ");
        scanf("%d", &m1);
        printf("Enter mark-2    : ");
        scanf("%d", &m2);
        printf("Enter mark-3    : ");
        scanf("%d", &m3);
        printf("Enter mark-4    : ");
        scanf("%d", &m4);
        printf("Enter mark-5    : ");
        scanf("%d", &m5);
        sum = m1 + m2 + m3 + m4 + m5;
        avg = (float)sum / 5.0;

        fprintf(fp, "%d\t%12s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\n", sno,
                                                          name,
                                                          m1,
                                                          m2,
                                                          m3,
                                                          m4,
                                                          m5,
                                                          sum,
                                                          avg);
    }

    fclose(fp);
    return 0;
} 

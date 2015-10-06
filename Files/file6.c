#include <stdio.h>

struct str
{
    int sno;
    char name[100];
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int sum;
    float avg;
};

int main(int argc, char *argv[])
{
    FILE *fp;
    char dummy[100];
    struct str s;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: Opening %s\n", argv[1]);
        return -1;
    }

    fgets(dummy, 100, fp);
    fgets(dummy, 100, fp);
    fgets(dummy, 100, fp);

    while(!feof(fp))
    {
        fscanf(fp, "%d %s %d %d %d %d %d %d %f", &s.sno,
                                                 s.name,
                                                 &s.m1,
                                                 &s.m2, &s.m3, &s.m4, &s.m5, &s.sum, &s.avg);
        fprintf(stdout, "%d\t%12s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\n", s.sno, s.name, s.m1, s.m2, s.m3, s.m4, s.m5, s.sum, s.avg);
    }

    fclose(fp);
    return 0;
}

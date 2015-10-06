#include <stdio.h>

#define KK

void main()
{
#ifdef KK
    printf("KK ");
#else
    printf("Karthick ");
#endif
    printf("rocks ...\n");
}

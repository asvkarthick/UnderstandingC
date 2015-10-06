#include <stdio.h>

#define KK

#undef KK

void main()
{
#ifndef KK
    printf("KK ");
#else
    printf("Karthick ");
#endif
    printf("rocks ...\n");
}

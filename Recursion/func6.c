#include <stdio.h>

#define WIDTH  640
#define HEIGHT 480
#define FRAMES 15

void main()
{
    unsigned char YUV[WIDTH * HEIGHT * FRAMES];

    printf("Size of YUV = %d\n", sizeof(YUV));
}

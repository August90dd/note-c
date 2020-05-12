#include <stdio.h>


struct circle {
    int x;
    int y;
    int radius;
};

static struct circle c[] = {
    {
        .x = 1,
        .y = 2,
        .radius = 3,
    },
    {
        .x = 3,
        .y = 4,
        .radius = 5,
    },
    {
        .radius = 8
    }
};

int main()
{
    printf("%d, %d, %d\n", c[0].x, c[1].y, c[2].radius);
    return 0;
}

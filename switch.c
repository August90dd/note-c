#include <stdio.h>

int main(void)
{
    int i = 12;
    switch (i) {
    default:
        printf("default!\n");
        //break;
    case 1:
        printf("1\n");
    case 2 ... 8:
        printf("%d\n", i);
    case 9:
        printf("9\n");
    }
    return 0;
}

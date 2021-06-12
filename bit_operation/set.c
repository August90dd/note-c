#include <stdio.h>

int main()
{
    int a = 0x0;

    a |= (1 << 0);
    printf("%0x\n", a);

    a |= (1 << 1);
    printf("%0x\n", a);

    a |= (1 << 2);
    printf("%0x\n", a);

    a |= (1 << 3);
    printf("%0x\n", a);

    return 0;
}

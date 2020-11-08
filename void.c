#include <stdio.h>

void main(void)
{
    int i = 1;
    void *v = &i; // ok

    //printf("%d\n", *v); // error
    printf("%d\n", *(int *)v); // ok

    int *ip = v; // ok
    printf("%d\n", *ip);

    if (ip == v)
        printf("ok\n");
}

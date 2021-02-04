#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    char array[0];
} softarray;


void test()
{
    int len = 10;

    softarray *p = (softarray*)malloc(sizeof(softarray)+sizeof(int)*len);

    p->len = len;

    for (int i = 0; i < p->len; i++)
        p->array[i] = i+1;

    for (int i = 0; i < p->len; i++)
        printf("%d\n", p->array[i]);

    memcpy(p->array, "hello", 5);
    for (int i = 0; i < p->len; i++)
        printf("%c\n", p->array[i]);

    free(p);
}

int main()
{
    printf("The struct's size is %lu\n",sizeof(softarray));
    test();
    return 0;
}

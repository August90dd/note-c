#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
    int *p = malloc(9);
    int nbytes = malloc_usable_size(p);
    printf("%d\n", nbytes);
    return 0;
}

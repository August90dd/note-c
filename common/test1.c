#include <stdio.h>
 
int init;
 
void init1()
{
    if (0 == init) {
        init = 1;
        printf("init1\n");
    }
}

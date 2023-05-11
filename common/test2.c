#include <stdio.h>
 
int init = 1;
 
void init2()
{
    if (init) {
        init = 0;
        printf("init2\n");
    }
}

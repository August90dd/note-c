#include <stdio.h>

#define CASE    2

int main()
{
#if CASE == 1
    printf("case1\n");
#elif CASE == 2
    printf("case2\n");
#else
    printf("default: not defined\n");
#endif
    return 0;
}

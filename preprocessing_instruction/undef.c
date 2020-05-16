/*
 * #undef用来撤销宏定义
 * 宏的生命周期从#define开始到#undef结束.
 */
#include <stdio.h>

#define X   3
#define Y   X * 2
#undef  X

#define X   2


int main(void)
{
    printf("%d\n", Y);
    return 0;
}

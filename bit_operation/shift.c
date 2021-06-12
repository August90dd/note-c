#include <stdio.h>

int main()
{
    int i = 0xcffffff3;
    printf("%x\n", 0xcffffff3 >> 2); // 字面值按无符号处理, 前补0.
    printf("%x\n", i >> 2); // 有符号数, 前补1.
    return 0;
}

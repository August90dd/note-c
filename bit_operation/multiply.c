/* 用位操作实现无符号整数的乘法运算:
 * e.g. (11011)2 * (10010)2
 * 相当于11011*10 + 11011*10000, 即
 * (11011)2 * (10010)2 == ((11011)2 << 1) + ((11011)2 << 4) 
 */
#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    int ret = 0;
    for (int i = 0; i < sizeof(unsigned int)*8; i++)
        if (y >> i & 0x1)
            ret += x << i;
    return ret;
}

int main()
{
    printf("%d\n", multiply(6, 7));
    return 0;
}

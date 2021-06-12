/* 对一个32位无符号整数做循环右移(把低位移出去的部分补回高位) 
 * e.g. 0xdeadbeef -8-> 0xefdeadbe */
#include <stdio.h>

unsigned int rotate_right(unsigned int x, int n)
{
    unsigned int i = x;
    int msb = 0;
    while (i >>= 1)
        msb++; // 获得最高有效位MSB

    unsigned char y;
    for (i = 0; i < n; i++) {
        y = x & 0x1;
        x >>= 1;
        if (y)
            x |= 1 << msb;
    }
    
    return x;
}

int main()
{
    printf("%x\n", rotate_right(0xdeadbeef, 8));
    return 0;
}

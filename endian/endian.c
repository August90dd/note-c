#include <stdio.h>

int main()
{
    unsigned int n = 0x12345678;
    unsigned char *p = (unsigned char *)&n; // 转换成char*, 是因为char*类型指针+1移动1byte, 而int*类型指针+1移动4bytes.

    printf("0x12345678[0]=%x\n", p[0]); // *p
    printf("0x12345678[1]=%x\n", p[1]); // *(p+1)
    printf("0x12345678[2]=%x\n", p[2]); // *(p+2)
    printf("0x12345678[3]=%x\n", p[3]); // *(p+3)

    return 0;
}

/*
 * # 运算符将一个宏的参数转换为字符串常量.
 * 其仅允许出现在带参数的宏的替换列表中(能够字符串化操作的必须是宏参数).
 */
#include <stdio.h>

#define PRINT_INT(x)    printf(#x "=%d\n", x)

int main(void)
{
    int i = 9;
    int j = 3;

    PRINT_INT(i/j); // printf("i/j" "=%d\n", i/j);
                    // C语言中相邻的字符串字面量会被合并, 等价于:
                    // printf("i/j=%d\n", i/j);

    return 0;
}

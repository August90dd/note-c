/* 位运算比较高效
 * a % b，当b为2的n次方时，取余有如下替换公式：a % 2^n == a & (2^n-1)
 */

#include <stdio.h>

int main(void)
{
    int a = 99;
    int b = 4;
    printf("%d\n", a % b);
    printf("%d\n", a & (b-1));
    return 0;
}

/*
 * The Token-pasting operator is a preprocessor operator.
 * 用来将两个token"粘"在一起, 成为一个token, 它不能位于第一个token之前或最后一个token之后. 
 */
#include <stdio.h>

#define STR_CONCAT(x, y)    x##y

#define pr_debug(fmt, arg...)   \
    printf(fmt, ##arg)
/*
 * 使用 "##" 是为了处理arg不代表任何参数的情况, 这时候前面的逗号就变得多余了.
 * 使用 "##" 之后, GNU C 预处理器会丢弃前面的逗号, 下面代码:
 *  pr_debug("success!\n")
 *
 * 会被正确的扩展为:
 *  printf("success!\n")
 *
 * 而不是:
 *  printf("success!\n",)
 */

int main(void)
{
    printf("%d\n", STR_CONCAT(20, 50));

    char *filename = "ltp";
    int line = 100;
    pr_debug("%s:%d\n", filename, line);
    pr_debug("success!\n");

    return 0;
}

/*
 * ## 运算符可以将两个记号(例如标识符), "粘"在一起成为一个记号.
 */
#define RTE_DEFINE_PER_LCORE(type, name)    \
    __thread __typeof__(type) per_lcore_##name


#define pr_debug(fmt, arg...)   \
    printk(fmt, ##arg)
/*
 * 使用 "##" 是为了处理arg不代表任何参数的情况, 这时候, 前面的逗号就变得多余了.
 * 使用 "##" 之后, GNU C 预处理器会丢弃前面的逗号, 这样, 下面代码:
 *  pr_debug("success!\n")
 *
 * 会被正确的扩展为:
 *  printk("success!\n")
 *
 * 而不是:
 *  printk("success!\n",)
 */

int main(void)
{
    static RTE_DEFINE_PER_LCORE(struct list_head *, dp_vs_conn_tbl);

    pr_debug("%s:%d", filename, line);
    pr_debug("success!\n");

    return 0;
}

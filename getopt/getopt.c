/*
 * #include <unistd.h>
 * int getopt(int argc, char *const argv[],
 *            const char *optstring);
 * extern char *optarg;
 * extern int optind, opterr, optopt;
 *
 * i.   argc, argv是main函数的参数, optstring代表要处理的选项字符串.
 * ii.  如果选项字符串里的字母后面接着冒号":", 则表示还有相关参数, 全局变量optarg即会指向此额外参数.
 *      如果没有冒号, optarg为NULL.
 *      e.g. ./a.out -a a_arg -b b_arg
 *           a, b为选项
 *           a_arg, b_arg为参数
 * iii. 如果getopt()找不到符合的选项则打印出错信息, 将此字母保存在全局变量optopt中, 并返回'?'.
 *      如果不希望getopt()打印出错信息, 将全局变量opterr设置为0即可.
 * iv.  The variable optind is the index of the next element to be processed in argv.  
 *      The system initializes this value to 1.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int opt;
    //opterr = 0;
	while ((opt = getopt(argc, argv, "a:b")) != -1) {
		switch (opt) {
		case 'a':
            printf("option a: optarg=%s\n", optarg);
			break;
		case 'b':
            printf("option b: optarg=%s\n", optarg);
			break;
		default:	/* '?' */
            printf("optopt = %c\n", optopt);
            printf("opt = %c\n", opt);
            break;
		}
	}
    printf("optind=%d\n", optind);
    return 0;
}

/*
 * GETOPT(3)
 *
 * NAME
 * 	getopt - Parse command-line options
 *
 * SYNOPSIS
 * 	#include <unistd.h>
 *
 *      int getopt(int argc, char * const argv[], const char *optstring);
 *
 * DESCRIPTION
 * 	getopt()用来分析命令行参数.
 *      参数argc和argv是由main()传递的参数个数和内容, 参数optstring则代表将要处理的选项字符串.
 *
 *      此函数会返回在argv中下一个的选项字母, 此字母会对应参数optstring中的字母.
 *
 *      如果选项字符串里的字母后接着冒号":", 则表示还有相关的参数, 全局变量optarg即会指向此额外参数.
 *      (如果选项字符串里的字母后没有冒号":", 则optarg为NULL.)
 *
 *      如果getopt()找不到符合的参数则会打印出错信息, 并将全域变量optopt设为当前optstring的字符.
 *      如果不希望getopt()打印出错信息, 则只要将全域变量opterr设为0即可.
 *
 * RETURN VALUE
 * 	如果找到符合的参数则返回此参数字母,
 *      如果参数不包含在参数optstring的选项字母则返回"?"字符, 分析结束则返回-1.
 *
 * EXAMPLE
 * 	$ ./getopt -a a_arg -b b_arg -c c_arg -d d_arg -ef
 * 	option a: optarg=a_arg
 * 	option b: optarg=b_arg
 * 	option c: optarg=c_arg
 * 	option d: optarg=(null)
 * 	other option: e
 * 	other option: ?
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ch;
	opterr = 0;

	while ((ch = getopt(argc, argv, "a:b:c:de")) != -1) {
		switch (ch) {
		case 'a':
			printf("option a: optarg=%s\n", optarg);
			break;
		case 'b':
			printf("option b: optarg=%s\n", optarg);
			break;
		case 'c':
			printf("option c: optarg=%s\n", optarg);
			break;
		case 'd':
			printf("option d: optarg=%s\n", optarg);
			break;
		default:
			printf("other option: %c\n", ch);
		}
	}

	exit(0);
}

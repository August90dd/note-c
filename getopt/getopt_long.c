/*
 * int getopt_long(int argc, char *const argv[],
 *  const char *optstring,  // 包含了所有要定义的短选项, 每个选项都只用单个字母表示.
 *                          // 如果该选项需要参数, 则其后跟一个冒号.
 *                          // If the program accepts only long options, 
 *                          // then optstring should be specified as an empty string (""), not NULL.
 *  const struct option *longopts,
 *      struct option {
 *          const char *name;   // name of the long option
 *          int         has_arg;
 *                      // no_argument          0 选项没有参数
 *                      // required_argument    1 选项需要参数
 *                      // optional_argument    2 选项参数可选
 *          int        *flag;   // 一般赋为NULL, 当赋为NULL时getopt_long返回该结构val字段中的数值
 *          int         val;    // value to return 或是该长选项对应的短选项名称
 *      };
 *      该数据结构的最后一个元素, 要求所有域的内容为0, 即{NULL, 0, NULL, 0}
 *  int *longindex);    // 一般赋为NULL即可, 如果没有设置为NULL, 那么它就指向一个变量,
 *                      // 这个变量会被赋值为寻找到的长选项在longopts中索引值, 可以用于错误诊断.
 *
 *  RETURN VALUE
 *  i.   每次调用该函数, 它都会分析一个选项, 并且返回它的短选项, 如果分析完成, 即已经没有选项了, 则返回-1.
 *  ii.  如果getopt_long在分析选项时, 遇到一个没有定义过的选项, 则返回值为'?'.
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

const char *program_name;

void print_usage(FILE *stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [inputfile...]\n", program_name);
	fprintf(stream, 
            "-h --help Display this usage information.\n"
            "-o --output filename Output the file.\n");
    exit(exit_code);
}

int main(int argc, char *argv[])
{
	int opt = 0;
    const char *const short_options = "ho:";
	static struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"output", required_argument, 0, 'o'},
		{NULL, 0, NULL, 0} /* required at end of array */
	};
    const char *output_filename = NULL;

    program_name = argv[0];

	while ((opt = getopt_long(argc, argv, short_options,
				  long_options, NULL)) != -1) {
		switch (opt) {
		case 'h':   /* -h or --help */
            print_usage(stdout, 0);
		case 'o':   /* -o or --output */
            output_filename = optarg;
            printf("output_filename = %s\n", output_filename);
            break;
		default:    /* '?' */
			print_usage(stderr, 1);
		}
	}
    if (optind == 1) // 用于判断没有任何选项的情况
        print_usage(stderr, 1);

	exit(0);
}

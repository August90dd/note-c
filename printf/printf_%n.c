/*
 * int printf(const char *format, [argument]);
 * format参数输出的格式, 定义格式为: %[flags][width][.perc][F|N|h|l]type
 * 也就是有5类:
 * 1. flage 对齐, 如右对齐.
 * 2. width 显示数值的宽度
 * 3. perc  小数点后面的位数
 * 4. 指针是否是远指针或整数是否是长整数
 * 5. type  必备的, 含义如下:
 *  d 有符号10进制整数
 *  i 有符号10进制整数
 *  o 无符号8进制整数
 *  u 无符号10进制整数
 *  ...
 *
 * %后h已经代表了短整形数据, 为什么还要加d才可以正常显示?
 * 因为第5类是必备的, 其他4个是可选的, 而h不是第5类的(第4), 故需要后面带一个第5类的d或其他.
 * printf("MaxUnsShortint = %hu\n", MaxUnsShortint); 中%hu是4和5, 表示非负短整型数据, 但由于u和d都在第5类中, 故有其中一个就可以了.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	printf("hello%nworld\n", &i); /* printf把自己到该点已打出的字符总数放到相应变元指向的整形变量中 */
	printf("i = %d\n", i);
	printf("i = %i\n", i);

    unsigned short j = 0xf;
	printf("j = %hd\n", j);
	printf("j = %hx\n", j);

	exit(0);
}

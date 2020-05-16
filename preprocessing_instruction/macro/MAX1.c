#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int main(void)
{
	printf("max=%d\n", MAX(1, 2));
	printf("max=%d\n", MAX(2, 1));
	printf("max=%d\n", MAX(2, 2));
	printf("max=%d\n", MAX(1 != 1, 1 != 2)); // 预期不符, > 的优先级大于 !=
	return 0;
}

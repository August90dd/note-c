#include <stdio.h>

#define MAX(x,y) (x) > (y) ? (x) : (y)

int main(void)
{
	printf("max=%d\n", MAX(1 != 1, 1 != 2));
	printf("max=%d\n", 3 + MAX(1, 2)); // 与预期不符, + 优先级大于 >
	return 0;
}

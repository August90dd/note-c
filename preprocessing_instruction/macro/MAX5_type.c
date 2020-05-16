#include <stdio.h>

/*
 * 在这个宏中, 我们添加一个参数: type, 用来指定临时变量 _x 和 _y 的类型. 
 * 这样, 在比较两个数的大小时, 只要将2个数据的类型作为参数传递给宏, 就可以比较任意类型的数据.
 */
#define MAX(type,x,y)({ \
    type _x = x;        \
    type _y = y;        \
    _x > _y ? _x : _y;  \
})

int main(void)
{
	int i = 2;
	int j = 6;
	printf("max=%d\n", MAX(int, i++, j++));
	printf("max=%f\n", MAX(float, 3.14, 3.15));
	return 0;
}

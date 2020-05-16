#include <stdio.h>

/*
 * 在语句表达式中, 我们定义了2个局部变量  _x , _y  来存储宏参数 x 和 y 的值, 
 * 然后使用 _x 和 _y 来比较大小, 这样就避免了 i 和 j 带来的2次自增运算问题.
 */
#define MAX(x,y)({      \
    int _x = x;         \
    int _y = y;         \
    _x > _y ? _x : _y;  \
})

int main(void)
{
	int i = 2;
	int j = 6;
	printf("max=%d\n", MAX(i++, j++));
	return 0;
}

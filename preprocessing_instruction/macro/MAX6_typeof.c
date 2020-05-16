#include <stdio.h>

/*
 * GNU C 扩展了一个关键字 typeof, 用来获取一个变量或表达式的类型.
 *
 * (void) (&_x == &_y);
 * 此句一是用来给用户提示一个警告, 对于不同类型的指针比较, 编译器会给一个警告, 提示两种数据类型不同;
 * 二是当两个值比较, 比较的结果没有用到, 有些编译器可能会给出一个warning, 加个(void)后, 就可以消除这个警告.
 */
#define MAX(x, y) ({    \
    typeof(x) _x = (x); \
    typeof(y) _y = (y); \
    (void) (&_x == &_y);\
    _x > _y ? _x : _y;  \
})

int main(void)
{
    printf("max = %d\n", MAX(3, 4));
    printf("max = %d\n", MAX(2, 1));

    printf("max = %d\n", MAX(0 != 0, 0 != 1));

    printf("x = %d\n", 3 + MAX(1, 2));

    int i = 2;
    int j = 6;
    printf("max = %d\n", MAX(i++, j++));
    printf("max = %f\n", MAX(3.14, 3.15));
    printf("max = %f\n", MAX(3.14, 3)); // Warning

    return 0;
}

#include <stdio.h>

/*
 * do {} while (0) 的使用完全是为了保证宏定义的使用者能无编译错误地使用宏, 它不对使用者做任何假设.
 */
#define SWAP(a, b)          \
do {                        \
    typeof(a) _tmp = (a);   \
    (a) = (b);              \
    (b) = _tmp;             \
} while (0)

int main(void)
{
    int i = 0;
    int j = 1;

    SWAP(i, j);

    printf("i = %d, j = %d\n", i, j);

    return 0;
}

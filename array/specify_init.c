#include <stdio.h>


int main(void)
{
    int arr[10] = {
        [1] = 1,
        [3] = 3,
        [5] = 5,
        [6 ... 9] = 9,  // GNU C 支持使用 ... 表示范围扩展, 
                        // 这个特性不仅可以使用在数组初始化中, 也可以使用在 switch-case 语句中.
    };

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d\n", arr[i]);

    return 0;
}

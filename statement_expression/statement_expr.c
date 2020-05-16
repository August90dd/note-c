#include <stdio.h>

int main(void)
{
    int sum = 0;
    sum = 
    ({
        int s = 0;
        for (int i = 0; i < 10; i++)
            s = s + i;
        s; // 语句表达式的值等于最后一个表达式的值, 如果不加此句, sum仍为0.
    });
    printf("sum = %d\n", sum);
    return 0;
}

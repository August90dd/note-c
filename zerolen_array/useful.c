/*
 * 零长度数组经常以变长结构体的形式，在某些特殊的应用场合使用。
 * 在一个变长结构体中，零长度数组不占用结构体的存储空间，但是我们可以通过使用结构体的成员去访问内存。
 * 创建该结构对象时，可以根据实际的需要指定这个可变长数组的长度，并分配相应的空间。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct buffer {
    int len;
    char a[0];
};

int main()
{
    struct buffer *buf = (struct buffer *)malloc(sizeof(struct buffer) + 20);
    buf->len = 20;
    memset(buf->a, 0x0, 20);

    strcpy(buf->a, "hello zero len array");
    puts(buf->a);

    free(buf);

    return 0;
}

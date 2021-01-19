/*
 * i.   第一个成员与结构体变量的偏移量为0.
 * ii.  每个成员存放的起始地址相对于结构的起始地址的偏移量, 必须为对齐数的整数倍.
 *      对齐数是编译器预设的一个对齐整数与该成员大小的较小值(e.g. example1中的成员b1, 对齐到4bytes), 
 *      gcc默认值为8, 可以通过#pragma pack(n)修改.
 * iii. 为了保证结构体的大小为最大对齐数的倍数, 在为最后一个成员变量申请空间后, 还会根据需要自动填充空缺的字节.
 */
#include <stdio.h>
#include <stddef.h>

#pragma pack (8) // 修改编译器默认对齐数
struct example1 {
	short a1; // 2+2
	int b1; // 4 
};

struct example2 {
	char a2; // 1+3
	struct example1 b2; // 8
	short c2; // 2+2
}; // 注意取结构体成员最大对齐数进行对齐, 而不是整个结构体(struct example1)大小.
#pragma pack () // 恢复默认值

struct example3 {
    short a3; // 2
    char b3; // 1+5
    //__attribute__ ((aligned(16))) // 设置对齐16byte
    long c3; // 8
    char d3; // 1+1
    short e3; // 2+4
}; //__attribute__ ((packed)); // 取消对齐

struct example4 {
    char a4; // 1+7
    struct inner {
        char *b4; // 8
        short c4; // 2+6
    } d4; // 16
    int e4; // 4
    char f4; // 1+3
};

struct example5 {
    union U {
        int a5;
        short b5;
        char c5;
    }; // 未定义变量!
    double d5; // 8
    char e5; // 1+7
};

struct example6 {
    int inode;  // 4
    short rec_len;  // 2
    char name_len;  // 1
    char file_type; // 1
    char *name;     // 8
};


int main()
{
    printf("sizeof(exmaple1)=%lu\n", sizeof(struct example1));
    printf("offset(a1)=%ld, offset(b1)=%ld\n", offsetof(struct example1, a1), offsetof(struct example1, b1));

    printf("sizeof(exmaple2)=%lu\n", sizeof(struct example2));
    printf("offset(b2)=%ld\n", ((unsigned long)&((struct example2 *)0)->b2));

    printf("sizeof(exmaple3)=%lu\n", sizeof(struct example3));
    printf("offset(b3)=%ld\n", ((unsigned long)&((struct example3 *)0)->b3));
    printf("offset(c3)=%ld\n", ((unsigned long)&((struct example3 *)0)->c3));
    printf("offset(d3)=%ld\n", ((unsigned long)&((struct example3 *)0)->d3));
    printf("offset(e3)=%ld\n", ((unsigned long)&((struct example3 *)0)->e3));

    printf("sizeof(exmaple4)=%lu\n", sizeof(struct example4));
    printf("offset(c4)=%ld\n", ((unsigned long)&((struct example4 *)0)->d4.c4));

    printf("sizeof(exmaple5)=%lu\n", sizeof(struct example5));
    printf("offset(d5)=%ld, offset(e5)=%ld\n", offsetof(struct example5, d5), offsetof(struct example5, e5));

    printf("sizeof(exmaple6)=%lu\n", sizeof(struct example6));
    printf("offset(name_len)=%ld, offset(file_type)=%ld, offset(name)=%ld\n", offsetof(struct example6, name_len), offsetof(struct example6, file_type), offsetof(struct example6, name));
	return 0;
}

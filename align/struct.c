/*
 * i.   第一个成员与结构体变量的偏移量为0.
 * ii.  每个成员存放的起始地址相对于结构的起始地址的偏移量, 必须为对齐数的整数倍.
 *      对齐数取编译器预设的一个值(gcc默认为8, 可以通过#pragma pack(n)或__attribute__((aligned(x)))修改)
 *      与该成员大小的较小值(e.g. example1中的成员b, offset为4而非8). 
 * iii. 为了保证结构体的大小为最大对齐数的倍数, 在为最后一个成员变量申请空间后, 还会根据需要填充空缺的字节.
 *      (e.g. example4中的c, +6字节)
 */
#include <stdio.h>
#include <stddef.h>

#pragma pack (4) // 修改编译器默认对齐数
struct example0 {
	char a;     // 1+3
	double b;   // 8
    char c;     // 1+3
};
#pragma pack () // 恢复默认值

struct example1 {
	short a;    // 2+2
	int b;      // 4 
};

struct example2 {
	char a;     // 1+3
	struct example1 b;  // 8
	short c;    // 2+2
}; // 注意取结构体成员最大对齐数进行对齐, 而不是整个结构体(struct example1)大小.

struct example3 {
    short a;    // 2
    char b;     // 1+5
    //__attribute__ ((aligned(16))) // 设置对齐16byte
    long c;     // 8
    char d;     // 1+1
    short e;    // 2+4
};  //__attribute__ ((packed)); // 取消对齐

struct example4 {
    char a; // 1+7
    struct inner {
        char *b;    // 8
        short c;    // 2+6
    } d;    // 16
    int e;  // 4
    char f; // 1+3
};

struct example5 {
    union U {
        int a;
        short b;
        char c;
    };  // 未定义变量!
    double d;   // 8
    char e;     // 1+7
};

struct example6 {
    int a;      // 4
    short b;    // 2
    char c;     // 1
    char d;     // 1
    char *e;    // 8
};


int main()
{
    printf("sizeof(example0)=%lu\n", sizeof(struct example0));

    printf("\nsizeof(exmaple1)=%lu\n", sizeof(struct example1));
    printf("example1: offset(a)=%ld, offset(b)=%ld\n", offsetof(struct example1, a), offsetof(struct example1, b));

    printf("\nsizeof(exmaple2)=%lu\n", sizeof(struct example2));
    printf("exmaple2: offset(b)=%ld\n", ((unsigned long)&((struct example2 *)0)->b));

    printf("\nsizeof(exmaple3)=%lu\n", sizeof(struct example3));
    printf("exmaple3: offset(b)=%ld\n", ((unsigned long)&((struct example3 *)0)->b));
    printf("exmaple3: offset(c)=%ld\n", ((unsigned long)&((struct example3 *)0)->c));
    printf("exmaple3: offset(d)=%ld\n", ((unsigned long)&((struct example3 *)0)->d));
    printf("exmaple3: offset(e)=%ld\n", ((unsigned long)&((struct example3 *)0)->e));

    printf("\nsizeof(exmaple4)=%lu\n", sizeof(struct example4));
    printf("exmaple4: offset(c)=%ld\n", ((unsigned long)&((struct example4 *)0)->d.c));

    printf("\nsizeof(exmaple5)=%lu\n", sizeof(struct example5));
    printf("exmaple5: offset(d)=%ld\n", offsetof(struct example5, d));

    printf("\nsizeof(exmaple6)=%lu\n", sizeof(struct example6));
    printf("exmaple6: offset(c)=%ld, offset(d)=%ld\n", offsetof(struct example6, c), offsetof(struct example6, d));
	return 0;
}

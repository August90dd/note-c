/*
 * 位段的声明和struct类似, 成员是一个或多个位的字段, 这些字段在实际存储可能存储在一个或多个整型变量中.
 * 在声明时, 位段成员必须是整形或枚举类型(通常是无符号类型), 且在成员名的后面是一个冒号和一个整数, 整数规定了成员所占用的位数.
 * 位域不能是静态类型, 不能使用&对位域做取地址运算.
 * 如果位域的定义没有给出标识符名字, 那么这是无名位域, 无法被初始化.
 * 无名位域用于填充(padding)内存布局, 只有无名位域的比特数可以为0. 
 * 这种占0比特的无名位域, 用于强迫下一个位域在内存分配边界对齐, 并且位段在定义时, 其最大长度不能超过依附类型的长度.
 *
 * i.   如果相邻位域字段的类型相同, 且其位宽之和小于类型的sizeof大小, 则后面的字段将紧邻前一个字段存储, 直到不能容纳为止.
 * ii.  如果相邻位域字段的类型相同, 但其位宽之和大于类型的sizeof大小, 则后面的字段将从新的存储单元开始, 其偏移量为其类型大小的整数倍.
 * iii. 如果相邻的位域字段的类型不同, 则各编译器的具体实现有差异.
 * iv.  如果位域字段之间穿插着非位域字段, 则不进行压缩.
 * v.   整个结构体的总大小为最宽基本类型成员大小的整数倍, 而位域则按照其最宽类型字节数对齐.
 */
#include <stdio.h>

struct foo1 {
    short s; // 2
    char c; // 1+1
    int flip:1;
    int nybble:4;
    int septet:7;
    // 4
};
struct foo2 { // 4
    int bigfield:31;
    int littlefield:1;
};
struct foo3 { // 4 + 4
    int bigfield1:31;
    int littlefield1:1;
    int bigfield2:31;
    int littlefield2:1;
};
struct foo4 { // 4 + 4 + 4 
    int bigfield1:31;
    int bigfield2:31;
    int littlefield1:1;
    int littlefield2:1;
};

int main()
{
    printf("%lu\n", sizeof(struct foo1));
    printf("%lu\n", sizeof(struct foo2));
    printf("%lu\n", sizeof(struct foo3));
    printf("%lu\n", sizeof(struct foo4));

    return 0;
}

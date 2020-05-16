#define PI  3.1415926
#define MAX(a, b) (a)>(b) ? (a):(b)


// 首先定义两个辅助宏
#define PRINT_MACRO_HELPER(x)   #x
#define PRINT_MACRO(x)  #x"="PRINT_MACRO_HELPER(x)

// 编译阶段打印宏内容
#pragma message("pragma message test")
#pragma message(PRINT_MACRO(PI))
#pragma message(PRINT_MACRO(notdefined))
#pragma message(PRINT_MACRO(MAX(x,y)))

int main()
{ return 0; }

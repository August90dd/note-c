#include <stdio.h>

int main()
{
#ifdef MIPS
    printf("mips\n");
#elif defined(ARM) || defined(ARM64)
    printf("arm\n");
#elif defined(x86)
    printf("x86\n");
#elif defined(i386)
    printf("i386\n");
#else
    printf("not defined\n");
#endif
    return 0;
}

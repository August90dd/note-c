#include <stdio.h>

#define ARM64
#define x64

int main()
{
#if defined(ARM) || defined(ARM64)
    printf("arm arch\n");
#endif

#if defined(x86) && !defined(x86_64) && !defined(x64)
    printf("x86 arch\n");
#elif defined(x86_64) || defined(x64) && !defined(x86)
    printf("x86_64 arch\n");
#endif

#if __GNUC__ >= 5
    printf("gcc version >=5\n");
#endif

    return 0;
}

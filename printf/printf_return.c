/*
 * Upon successful return, the printf functions return the number of characters printed 
 * (not including the trailing '\0' used to end output to strings).
 */

#include <stdio.h>

int main()
{
	int ret;

	ret = printf("\0");
	printf("%d\n", ret);

    return 0;
}

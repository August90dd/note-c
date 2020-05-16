#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void)
{
	printf("max=%d\n", 3 + MAX(1, 2));
	int i = 2;
	int j = 6;
	printf("max=%d\n", MAX(i++, j++));
	return 0;
}

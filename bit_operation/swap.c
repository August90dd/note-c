#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 0;
	int j = 1;
	i = i + j;
	j = i - j;
	i = i - j;
	printf("i=%d\n", i);
	printf("j=%d\n", j);

	i ^= j;
	j ^= i;
	i ^= j;
	printf("i=%d\n", i);
	printf("j=%d\n", j);

	return 0;
}

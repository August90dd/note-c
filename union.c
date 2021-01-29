#include <stdio.h>

union data {
	int n;
	char ch;
	short m;
};

int main()
{
	union data a;
	printf("%ld, %ld\n", sizeof(a), sizeof(union data));

	a.n = 0x40;
	printf("%x, %c, %hx\n", a.n, a.ch, a.m);

	a.ch = '9';
	printf("%x, %c, %hx\n", a.n, a.ch, a.m);

	a.m = 0x2059;
	printf("%x, %c, %hx\n", a.n, a.ch, a.m);

	a.n = 0x3E25AD54;
	printf("%x, %c, %hx\n", a.n, a.ch, a.m);

	return 0;
}

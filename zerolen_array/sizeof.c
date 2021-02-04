#include <stdio.h>

int buffer0[0];

struct buffer1 {
    int len;
    int a[0];
};

struct buffer2 {
    int len;
    int *a;
};

int main()
{
	printf("sizeof(buffer0)=%ld\n", sizeof(buffer0));
	printf("sizeof(buffer1)=%ld\n", sizeof(struct buffer1));
	printf("sizeof(buffer2)=%ld\n", sizeof(struct buffer2));
    return 0;
}

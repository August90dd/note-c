#include <stdio.h>


int chk1()
{
	union chk {
		int n;
		char c;	
	} x;
	x.n = 1;
	return (x.c == 1);
}

int chk2()
{
    unsigned short usData = 0x1122;
    unsigned char *pucData = (unsigned char *)&usData;
    return (*pucData == 0x22);
}

int chk3()
{
	unsigned int n = 1;
    return ((unsigned char *)&n)[0];
}

int main()
{
	if (chk3())
		printf("little-endian\n");
	else
		printf("big-endian\n");

	return 0;
}

#include <stdio.h>
#include "main.h"

int main(void)
{
	int len = 0, len2 = 0;

	len = printf("%x\n", 12);
	len2 = _printf("%x\n", 12);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("%x\n", 1024);
	len2 = _printf("%x\n", 1024);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("%x\n", -312);
	len2 = _printf("%x\n", -312);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("%x\n", 10000);
	len2 = _printf("%x\n", 10000);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("some before %x\n", 10000);
	len2 = _printf("some before %x\n", 10000);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("%Xsome after\n", -1024);
	len2 = _printf("%Xsome after\n", -1024);
	printf("native len is %d, pits is %d\n", len, len2);

	len = printf("before %X and after\n", 10000);
	len2 = _printf("before %X and after\n", 10000);
	printf("native len is %d, pits is %d\n", len, len2);
	return (0);
}

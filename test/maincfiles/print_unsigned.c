#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int print_unsigned(long int number)
{
	unsigned int num;
	int len, i;
	char *reverse_number;

	while (number >=0)
	{
		number = number / 2;
		len++;
	}
	
	return (len);
}

int main(void)
{
	print_unsigned(12345);
	_putchar('\n');
	print_unsigned(666666);
	_putchar('\n');
	print_unsigned(1234567);
	_putchar('\n');
	print_unsigned(12345678);
	_putchar('\n');
	print_unsigned(1234567890);
	_putchar('\n');
	print_unsigned(UINT_MAX - 2);
	_putchar('\n');

	return (0);
}

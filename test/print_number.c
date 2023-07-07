#include <stdlib.h>
#include "main.h"
/**
 * print_number - prints the number supplied on screen
 * @pos: current position in the larger string
 * @number: number to print
 * Return: length of number printed
 */

int print_number(int *pos, long int number)
{
	int len = 0;
	int i, ascii_dec;
	long int num = (number < 0) ? number * -1 : number;
	char *reverse_num;

	while ((num / 10 != 0) && num > 9)
	{
		num = num / 10;
		len++;
	}

	len += 1;
	num = (number < 0) ? number * -1 : number;
	reverse_num = malloc(sizeof(char) * len);
	if (reverse_num == NULL)
	{
		free(reverse_num);
		return (0);
	}

	for (i = 0; i < len; i++)
	{
		ascii_dec = num_to_char(num % 10);
		reverse_num[i] = ascii_dec;
		num = num / 10;
	}
	i--;
	if (number < 0)
	{
		len++;
		_putchar('-');
	}
	for (; i >= 0; i--)
	{
		_putchar(reverse_num[i]);
	}

	free(reverse_num);
	*pos = *pos + 2;
	return (len);
}

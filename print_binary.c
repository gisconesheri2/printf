#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_binary - converts number into binary format
 * @number: an unsigned int to be converted
 * @pos: current position within the larger string being printed
 * Return: length of the binary printed out
 */

int print_binary(int *pos, int number)
{
	char *binary_reversed;
	int num = number < 0 ? number * -1 : number;
	int len = 0;
	int i = 0;

	for (; num > 0; len++)
		num = num / 2;
	if (number < 0)
	{
		binary_reversed = malloc(sizeof(char) * 32);
		if (binary_reversed == NULL)
			return (1);
		num = number * -1;
		for (; num > 0; i++, num /= 2)
			binary_reversed[i] = num_to_char(num % 2);
		for (; i < 32; i++)
			binary_reversed[i] = num_to_char(1);
		len = 32;
	}
	if (number > 0)
	{
		binary_reversed = malloc(sizeof(char) * len);
		if (binary_reversed == NULL)
			return (1);
		num = number;
		for (; num > 0; i++, num /= 2)
			binary_reversed[i] = num_to_char(num % 2);
	}
	if (number == 0)
	{
		binary_reversed = malloc(sizeof(char) * 1);
		if (binary_reversed == NULL)
			return (1);
		binary_reversed[0] = num_to_char(0);
		i = 1;
		len = 1;
	}
	i--;
	for (; i >= 0; i--)
		_putchar(binary_reversed[i]);
	*pos = *pos + 2;
	free(binary_reversed);

	return (len);
}

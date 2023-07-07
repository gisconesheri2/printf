#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_binary_positive - convert a number into binary
 * @n: number to convert
 * Return: pointer to an array of 1s and 0s representing n
 */
char *get_binary_positive(long int n)
{
	long int temp_n2 = n;
	long int temp_n;
	long int times, i = 0;
	char *binary_reversed;

	binary_reversed = malloc(sizeof(char) * 32);
	if (binary_reversed == NULL)
		return (NULL);
	/* fill all bits with 0s*/
	for (; i < 32; i++)
		binary_reversed[i] = '0';
	/* handle the number 1 not touched by loop*/
	if (temp_n2 == 1)
		binary_reversed[0] = '1';
	/* generate the binary string by not using / or % */
	while (temp_n2 > 1)
	{
		temp_n = temp_n2;
		times = 0;
		while (temp_n > 1)
		{
			temp_n = temp_n >> 1;
			times++;
		}

		binary_reversed[times] = '1';
		temp_n2 = temp_n2 - (exponent_num(2, times));
	}

	if (temp_n2 == 1)
		binary_reversed[0] = '1';
	return (binary_reversed);
}

/**
 * binary_to_uint - convert a string of 0s and 1s to decimal number
 * @reverse_b: pointer to the string with binary numbers with 2 exponent 1
 * on the left
 * Return: converted number or 0 if conversion fails
 */

unsigned int binary_to_uint(char *reverse_b)
{
	unsigned int num = 0;
	unsigned int exponent_of_two = 0;

	unsigned long int len = 0;

	if (reverse_b == NULL)
		return (0);
	/*get corresponding unsigned int - calls the function exponent_two*/
	for (; len < 32; len++)
	{
		exponent_of_two = exponent_num(2, len);
		if (reverse_b[len] == '0')
			num = num + (0 * exponent_of_two);
		else if (reverse_b[len] == '1')
			num = num + (1 * exponent_of_two);
		else
			return (0);
	}
	free(reverse_b);
	return (num);
}
/**
 * print_unsigned - handles the %u format specifier for _printf
 * @n: number to print
 * @pos: current position within the larger string being printed
 *
 * Return: length of the printed number
 */

int print_unsigned(int *pos, long int n)
{
	char *binary_reversed;
	char *reverse_num;
	unsigned int num, num2 = 0;
	int len = 0;
	int i, ascii_dec;

	if (n < 0)
		binary_reversed = get_binary_negative(n);
	else
		binary_reversed = get_binary_positive(n);

	num = binary_to_uint(binary_reversed);
	num2 = num;
	while ((num / 10 != 0) && num > 9)
	{
		num = num / 10;
		len++;
	}
	len += 1;
	reverse_num = malloc(sizeof(char) * len);
	if (reverse_num == NULL)
	{
		free(reverse_num);
		return (0);
	}
	for (i = 0; i < len; i++)
	{
		ascii_dec = num_to_char(num2 % 10);
		reverse_num[i] = ascii_dec;
		num2 = num2 / 10;
	}
	i--;
	for (; i >= 0; i--)
	{
		_putchar(reverse_num[i]);
	}

	free(reverse_num);
	*pos = *pos + 2;
	return (len);
}

#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <limits.h>
/**
 * num_to_hex_letter - converts numbers 10-15 to corresponding hex letter A-F
 * @rem: number to convert to hex letter
 * Return: character ranging from A to F
 */

char num_to_hex_letter(long int rem)
{
	long int num = 10;
	char hex_let = 97;

	while (hex_let < 103)
	{
		if (rem == num)
			return (hex_let);
		num++;
		hex_let++;
	}
	return ('0');
}

/**
 * get_hex_positive - convert a positive number to hexadecimal form
 * @n: number to convert
 * Return: pointer to string containing the hexadecimal number in reverse
 */
char *get_hex_positive(long int n)
{
	char *rev_hex;
	long int num = n;
	int len, i;

	len = i = 0;
	for (; num >= 16; len++)
		num = num / 16;

	len += 1;
	rev_hex = malloc(sizeof(char) * len + 1);
	if (rev_hex == NULL)
		return (NULL);
	num = n;

	for (; i < len; i++)
	{
		if (num % 16 > 9)
			rev_hex[i] = num_to_hex_letter(num % 16);
		else
			rev_hex[i] = num_to_char(num % 16);
		num = num / 16;
	}
	rev_hex[len] = '\0';
	return (rev_hex);
}
/**
 * get_hex_negative - convert a negative number to hexadecimal form
 * @n: number to convert
 * Return: pointer to string containing the hexadecimal number in reverse
 */
char *get_hex_negative(long int n)
{
	char *reverse_binary;
	char *hexadecimal_num;
	long int num = n;
	int i, j, hex_num;
	int len = 0;

	i = j = hex_num = 0;
	/* call the get_binary_negative function to get the binary num of n*/
	reverse_binary = get_binary_negative(num);

	if (reverse_binary == NULL)
		return (NULL);
	hexadecimal_num = malloc(sizeof(char) * 12);

	/*get corresponding octal int - calls the function exponent_num*/
	for (; len < 32; )
	{
		hex_num = 0;
		/*convert the bits in groups of three to get the octal number*/
		for (j = 0; j < 4; j++)
		{
			if (reverse_binary[len] == '0')
				hex_num = hex_num + (0 * exponent_num(2, j));
			if (reverse_binary[len] == '1')
				hex_num = hex_num + (1 * exponent_num(2, j));
			len++;
		}
		if (hex_num > 9)
			hexadecimal_num[i] = num_to_hex_letter(hex_num);
		else
			hexadecimal_num[i] = num_to_char(hex_num);
		i++;
	}
	free(reverse_binary);
	return (hexadecimal_num);
}
/**
 * print_hexadecimal_small - print the reversed hexadecimal string onto stdout
 * @pos: current position in the larger string
 * @n: number recevied from _printf
 * Return: length of the string printed out
 */
int print_hexadecimal_small(int *pos, long int n)
{
	char *hex_reversed = "";
	int len = 0;
	int i = 0;

	if (n < 0)
		hex_reversed = get_hex_negative(n);
	else
	{
		if (n > UINT_MAX)
			n = n - UINT_MAX - 1;
		hex_reversed = get_hex_positive(n);
	}
	if (hex_reversed == NULL)
		return (0);

	while (hex_reversed[len] != '\0')
		len++;
	len--;
	for (; len >= 0; len--)
	{
		_putchar(hex_reversed[len]);
		i++;
	}
	*pos = *pos + 2;
	free(hex_reversed);
	return (i);
}

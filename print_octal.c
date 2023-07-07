#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * get_octal_positive - convert a negative number to octal form
 * @n: number to convert
 * Return: pointer to string containing the octal number in reverse
 */
char *get_octal_positive(long int n)
{
	char *rev_octal;
	long int num = n;
	int len, i;

	len = i = 0;
	while (num > 8)
	{
		len++;
		num = num / 8;
	}

	len += 1;
	rev_octal = malloc(sizeof(char) * len + 1);
	if (rev_octal == NULL)
		return (NULL);
	num = n;

	for (; i < len; i++)
	{
		rev_octal[i] = num_to_char(num % 8);
		num = num / 8;
	}
	rev_octal[len] = '\0';
	return (rev_octal);
}
/**
 * get_octal_negative - convert a negative number to octal form
 * @n: number to convert
 * Return: pointer to string containing the octal number in reverse
 */
char *get_octal_negative(long int n)
{
	char *reverse_binary;
	char *octal_num;
	long int num = n;
	int i, j, oct_num;
	int len = 0;

	i = j = oct_num = 0;
	/* call the get_binary_negative function to get the binary num of n*/
	reverse_binary = get_binary_negative(num);

	if (reverse_binary == NULL)
		return (NULL);
	octal_num = malloc(sizeof(char) * 12);

	/*get corresponding octal int - calls the function exponent_num*/
	for (; len < 32; )
	{
		oct_num = 0;
		/*convert the bits in groups of three to get the octal number*/
		for (j = 0; j < 3; j++)
		{
			if (reverse_binary[len] == '0')
				oct_num = oct_num + (0 * exponent_num(2, j));
			if (reverse_binary[len] == '1')
				oct_num = oct_num + (1 * exponent_num(2, j));
			len++;
		}
		octal_num[i] = num_to_char(oct_num);
		i++;
	}
	free(reverse_binary);
	return (octal_num);
}
/**
 * print_octal - print the reversed octal string onto stdout
 * @pos: current position in the larger string
 * @n: number recevied from _printf
 * Return: length of the string printed out
 */
int print_octal(int *pos, long int n)
{
	char *octal_reversed = "";
	int len = 0;
	int i = 0;

	if (n < 0)
		octal_reversed = get_octal_negative(n);
	else
		octal_reversed = get_octal_positive(n);

	if (octal_reversed == NULL)
		return (0);

	while (octal_reversed[len] != '\0')
	{
		len++;
	}
	len--;
	for (; len >= 0; len--)
	{
		_putchar(octal_reversed[len]);
		i++;
	}
	*pos = *pos + 2;
	free(octal_reversed);
	return (i);
}

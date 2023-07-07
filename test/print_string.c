#include "main.h"
#include <stddef.h>
/**
 * print_str - print a char to stdout
 * @pos: current position within the string being printed
 * @str_to_print: string to print
 * Return: length of the string printed
 */
int print_str(int *pos, char *str_to_print)
{
	int i;
	int len = 0;
	char null_s[6] = {'(', 'n', 'u', 'l', 'l', ')'};

	if (str_to_print == NULL)
	{
		for (i = 0; i < 6; i++)
		{
			_putchar(null_s[i]);
			len++;
		}
	}

	else
	{
		for (i = 0; str_to_print[i] != '\0'; i++)
		{
			_putchar(str_to_print[i]);
			len++;
		}
	}

	*pos = *pos + 2;
	return (len);
}

#include "main.h"
/**
 * print_char - print a char to stdout
 * @pos: current position within the string being printed
 * @char_to_print: character to print
 * Return: length of the character
 */
int print_char(int *pos, int char_to_print)
{
	int length = 0;

	_putchar(char_to_print);
	*pos = *pos + 2;
	length = 1;
	return (length);
}

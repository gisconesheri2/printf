#include <unistd.h>
/**
 * _putchar - writes c to the stdout
 * @c: character to print
 * Return: int for the c
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include <stdlib.h>
#include "main.h"
/**
 * num_to_char - converts given integer to corresponding ascii decimal char
 * @num: integer to convert to char
 * Return: corresponing ascii decimal char
 */

int num_to_char(int num)
{
	int ascii_num_dec = 48;
	int ascii_num = 0;

	while (ascii_num_dec < 58)
	{
		if (ascii_num == num)
		{
			return (ascii_num_dec);
		}
		ascii_num_dec++;
		ascii_num++;
	}
	return (48);
}

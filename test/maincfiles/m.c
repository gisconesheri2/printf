#include "main.h"
#include <stdio.h>

int main(void)
{

	int len, len1, len3, len4;

	_printf("this is a trial\n");
	len1 = _printf("this is a char %c\n", 'H');
	len = printf("this is a char %c\n", 'H');
	printf("len1 is %d, len is %d\n", len1, len);
	_printf("this %c is a char\n", 'R');
	_printf("%c is a char\n", 'R');
	len3 = _printf("this is a string: %s\n", "try try try");
	len4 = printf("this is a string: %s\n", "try try try");
	_printf("len1 is %d, len is %d\n", len3, len4);
	_printf("%c this is a string: %s\n", 'Q', "pi, pi, pi");
	_printf("this is %sa string: %s\n", "try try try", "pi, pi, pi");
	_printf("this is a percent [%%]\n");
	_printf("percent is [%%] a trial\n");
	_printf("%d negative", -762534);
	_printf("negative: %i\n", -762534);
	return (1);
}

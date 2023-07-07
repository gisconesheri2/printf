#include <stdlib.h>
/**
 * plus_one - logic for adding one to a 'twos-complement' binary string
 * @binary_reversed: a flipped binary string
 * Return: Nothing
 */

void plus_one(char *binary_reversed)
{
	int i = 0;

	for (; i < 32; i++)
	{
		if (binary_reversed[i] == '1')
		{
			binary_reversed[i] = '0';
			continue;
		}
		else if (binary_reversed[i] == '0')
		{
			binary_reversed[i] = '1';
			break;
		}
	}
}

/**
 * get_binary_negative - convert a number into binary
 * @n: number to convert
 * Return: pointer to an array of 1s and 0s representing n
 */
char *get_binary_negative(long int n)
{
	char *binary_reversed;
	long int num, rem, i, j;

	j = num = rem = i = 0;

	binary_reversed = malloc(sizeof(char) * 32);
	if (binary_reversed == NULL)
		return (NULL);
	num = n * -1;
	/* generate the 1s and 0s in reverse order*/
	while (num > 0)
	{
		rem = num % 2;
		if (rem == 1)
			binary_reversed[i] = '1';
		if (rem == 0)
			binary_reversed[i] = '0';
		num = num / 2;
		i++;
	}
	/* flip the the 1s and 0s to get the twos complement*/
	for (j = 0; j < i; j++)
	{
		if (binary_reversed[j] == '1')
			binary_reversed[j] = '0';
		else
			binary_reversed[j] = '1';
	}
	/* fill up remaining bits with 1s*/
	for (; i < 32; i++)
	{
		binary_reversed[i] = '1';
	}
	/*add one bit to the twos complement to get the finished binary string*/
	plus_one(binary_reversed);
	return (binary_reversed);
}


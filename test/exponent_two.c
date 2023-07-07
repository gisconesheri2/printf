/**
 * exponent_two - returns 2 to the power of times
 * @times: the exponent
 * Return: result of 2 to the power of 'times'
 */
unsigned long int exponent_num(unsigned int base, unsigned long int times)
{
	if (times == 0)
		return (1);
	return (base * exponent_num(base, times - 1));
}


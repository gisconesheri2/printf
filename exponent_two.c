/**
 * exponent_num - returns base to the power of times
 * @base: number with which to get the multiples of
 * @times: the exponent
 * Return: result of base to the power of 'times'
 */
unsigned long int exponent_num(unsigned int base, unsigned long int times)
{
	if (times == 0)
		return (1);
	return (base * exponent_num(base, times - 1));
}


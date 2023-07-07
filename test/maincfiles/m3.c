#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: 0 on success, error code otherwise
 *     */
int main(void)
{
		int len, len2;
			long int l = 0;
					printf("%ld\n", l);

				l += 10;
					len = _printf("%o", l);
					printf("\n");
						len2 = printf("%o", l);
					printf("\n");
							fflush(stdout);
								if (len != len2)
										{
													printf("_printf len is %d and printf len is %d Lengths differ.\n", len, len2);
															fflush(stdout);
																	return (1);
																		}
									return (0);
}

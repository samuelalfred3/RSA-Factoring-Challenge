#include "factors.h"

/**
 * factorize - Factorizes a number into two smaller numbers
 * @buffer: Pointer to the address of the number as a string
 *
 * Return: void
 */
int factorize(char *buffer)
{
	long num = atol(*buffer);
	long p, q;
	
	for (p = 2; p < num; p++)
	{
		if (num % p == 0)
		{
			q = num / p;
			printf("%ld=%ld*%ld\n", num, p, q);
			break;
		}
	}
}

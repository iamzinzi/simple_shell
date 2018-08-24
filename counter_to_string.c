#include "shell.h"

/**
 * counter_to_string - made my own ITOA
 * @i: an int of the counter we want to return as a char*
 * @to_string: pointer to string to be updated with number
 *
 * Description: cant use itoa. need to make my own
 * Return: the pointer to the string
 */

char *counter_to_string(int i, char *to_string)
{
	int div;
	int j = 0;

	for (div = 1; div <= i; div *= 10)
		;
	div /= 10;
	while (div > 0)
	{
		to_string[j] = (i / div + '0');
		i %= div;
		j++;
		div /= 10;
	}
	to_string[j] = '\0';
	return (to_string);
}

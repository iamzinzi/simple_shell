#include "shell.h"

/**
* string_to_int - convers a strint data type to an int.
* @s: the string we are given to turn into an int
*
* Description: our own atoi function. does not handle negatives
*       but that is becaues exit statuses are 0 and pos
* Return: an int that is the exit status
*/

int string_to_int(char *s)
{
	int result = 0;
	int i = 0;

	/* loop through string and update result by */
	/* multiplying by 10 first and then adding the digit */
	for (i = 0; s[i] != '\0'; i++)
	{
		result = result * 10 + s[i] - '0';
	}
	/* returns the result */
	return (result);
}


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

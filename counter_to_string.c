#include "shell.h"

/**
* counter_to_string - made my own ITOA
* @i: an int of the counter we want to return as a char*
*
* Description: cant use itoa. need to make myown
* Return: the pointer to the string so itoa.
*/

char *counter_to_string(int i, char *to_string)
{
	int div;
	//char *stringy;
	int j = 0;

//	stringy = to_string;
//	stringy = malloc(sizeof(char) * 16);
	for (div = 1; div <= i; div *= 10)
		;
	while (i > 0)
	{
		div /= 10;
		to_string[j] = (i / div + '0');
		i %= div;
		j++;
	}
	to_string[j] = '\0';
	return (to_string);
}

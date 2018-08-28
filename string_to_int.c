#include "shell.h"

/**
* string_to_int - convers a strint data type to an int.
*
* Description: our own atoi function. does not handle negatives
*	but that is becaues exit statuses are 0 and pos
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

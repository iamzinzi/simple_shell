#include "shell.h"

/**
* _strdup - function that behaves like the string.h strdup
* @s: the string we want to duplicate
*
* Description: cant use strdup due to requirements so we wrote our own
* Return: pointer to the duplicated string
*/

char *_strdup(char *s)
{
	int size;
	static char *dup;
	char *dup_offset;

	/* allocate memory for duplicate */
	size = _strlen(s);
	dup = malloc(sizeof(char) * size + 1);
	if (!dup)
		return (NULL);

	/* copy the string */
	dup_offset = dup;
	while (*s)
	{
		*dup_offset = *s;
		dup_offset++;
		s++;
	}
	*dup_offset = '\0';

	return (dup);
}

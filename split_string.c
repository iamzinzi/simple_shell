#include "shell.h"

/**
* word_count - returns number of words in a string
* @str: the string that we will scan
*
* Description: the main use of this function will be to
*	find how many words are in the stdin. like a argc counter
* Return: the number of words in the string
*/

int word_count(char *str)
{
	int i, count = 0;

	/* for each index until the null, see if it was a word */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
* split_string - splits a string into separate words
* @str: string to be tokenized
*
* Description: using space as a delimiter, we count how many words
* Return: array containing each word of the string
*/

char **split_string(char *str)
{
	int wc, i;
	char *token;
	char **words;

	wc = word_count(str);

	if (!wc)
		return (NULL);
	/* malloc the number of words plus a null */
	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);

	/* token stores the pointer that strtok returns*/
	token = strtok(str, " ");
	i = 0;

	/* loop to tokenize and store the pointer to each word in array */
	while (token)
	{
		words[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;

	return (words);
}

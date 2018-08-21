#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* word_count - returns number of words in a string
* @str: tje string that we will scan
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
* Description: using space as a delimiter, we count how mant words
* Return: array of each word of the string
*/

char **split_string(char *str)
{
	int wc, i;
	char *token;
	char **words;

	wc = word_count(str);

	/* malloc the number of words plus a null */
	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	/* token stores the pointer that strtok returns*/
	token = strtok(str, " ");
	i = 0;

	/* loop to tokenize and allocate space for each word */
	while (token)
	{
		words[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;

	return (words);
}

/**
* free_array_of_words - frees the malloc'd memory for the words
* @arr: the pointer to the word array
*
* Description: Frees stuff so no memory leaks
* Return: none it is void
*/

void free_array_of_words(char **arr)
{
	int size, i;

	for (size = 0; arr[size] != NULL; size++)
		;

	for (i = 0; i < size; i++)
	{
		free(arr[i]);
	}
}

/**
* main - function that tests this c file
* @argc: the number of arguments. will be unused
* @argv: the strings of strings. the values.
* Description: prints test and then splits words then it prints test2
*	then it prints the words and then frees the stuff
* Return: 0 is successful
*/

int main(int argc __attribute__((unused)), char *argv[])
{
	int i;
	int wc;
	char **words_to_print;

	wc = word_count(*argv);
	printf("test\n");
	words_to_print = split_string(argv[1]);
	printf("test2\n");

	for (i = 0; i < wc; i++)
		printf("Words_to_print[%d]: %s\n", i, words_to_print[i]);

	free_array_of_words(words_to_print);
	free(words_to_print);

	return (0);
}

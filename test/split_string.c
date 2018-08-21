#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * word_count - returns number of words in a string
 */
int word_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		    count++;
	}
	return (count);
}

/**
 * split_string - splits a string into separate words
 * @: str: string to be tokenized
 * Return: array of each word of the string
 */
char **split_string(char *str)
{
	int wc, i;
	char *token;
	char **words;

	wc = word_count(str);

	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return NULL;

	token = strtok(str, " ");
	i = 0;

	while (token)
	{
		words[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;

	return (words);
}

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
/*
int main(int argc __attribute__((unused)), char *argv[])
{
	int i;
	char **words_to_print;
	printf("test\n");
	words_to_print = split_string(argv[1]);
	printf("test2\n");

	for (i = 0; words_to_print[i] != NULL; i++)
		printf("%s\n", words_to_print[i]);

	free_array_of_words(words_to_print);
	free(words_to_print);

	return (0);
}
*/

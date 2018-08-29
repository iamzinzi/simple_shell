#include "shell.h"

/**
* print_env - prints the current env built in
*
* Return: none is void
*/

void print_env(void)
{

	int i = 0;

	/* prints in form of "variable=value" */
	while (environ[i])
	{
		write(STDIN_FILENO, environ[i], _strlen(environ[i]));
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
}

/**
* search_path - goes through the PATH to find a command that matches
* @head: the head node from the linked list
* @c: the string we have from the user command
* @av: the arguments from the CLI
* @to_string: the counter as an int but converted to a string
*
* Description: this tests if user has access permissions also
* Return: Null if no access or the string if we have access
*/

char *search_path(list_t *head, char *c, char **av, char *to_string)
{
	list_t *node;
/*	struct stat buf; */
	char *full_command;
	char *command = str_concat("/", c);

	for (node = head; node != NULL; node = node->next)
	{
		full_command = str_concat(node->str, command);
/*
*	if (stat(full_command, &buf) == 0)
*		return (full_command);
*/

		if (access(full_command, X_OK) == 0)
		{
			return (full_command);
		}
/*
*		if (access(full_command, X_OK) == 0)
*
*		{
*			write(STDOUT_FILENO, av[0], _strlen(av[0]));
*			write(STDOUT_FILENO, ": ", 2);
*			write(STDOUT_FILENO, to_string, _strlen(to_string));
*			write(STDOUT_FILENO, ": ", 2);
*			write(STDOUT_FILENO, c, _strlen(c));
*			write(STDOUT_FILENO, ": Permission denied\n", 20);
*			exit(0);
*		}
*/
		free(full_command);
	}

	free(command);
	return (NULL);
}

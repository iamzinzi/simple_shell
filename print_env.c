#include "shell.h"

/**
* main - prints the current env built in
*
* Return: none is void
*/

void print_env(void)
{

	int i = 0;

	/* prints in form of "variable=value" */
	while(environ[i])
	{
		write(STDIN_FILENO, environ[i], _strlen(environ[i]));
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
}

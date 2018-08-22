#include <stdio.h>
#include <unistd.h>
extern char **environ;

/**
* main - prints the environment using global variable
*
* Return: Always 0 unless errror
*/


int main(int ac, char **av, char **env)
{

	int i = 0;

	/* prints in form of "variable=value" */
	while(environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}

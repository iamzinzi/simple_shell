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

	/* prints the addresses of env and environ" */
	while(environ[i])
	{
		printf("Address of environ: %p\n", environ[i]);
		printf("Address of 3rd env: %p\n", env[i]);
		printf("\n");
		i++;
	}
	return (0);
}

#include "shell.h"

/**
 * main - super simple shell
 *
 * Return: 0 upon success
 */
int main(void)
{
	int status, i;
	char *buf = NULL;
	char **argv = NULL;
	pid_t child_pid;
	size_t buf_size = 0;

	while (1)
	{
		printf("#cisfun$ ");
		/* prompt user for command */
		getline(&buf, &buf_size, stdin);

		/* remove newline from string so program can execute*/
		i = strlen(buf);
		buf[i - 1] = '\0';

		/* create argument vector of CL arguments*/
		argv = split_string(buf);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}

	free(argv);
	free(buf);

	return (0);
}

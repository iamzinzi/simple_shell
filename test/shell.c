#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int word_count(char *str);
char **split_string(char *str);

/**
* main - super simple shell
*
* Description: this is a simple shell that should behave like bash
* Return: 0 upon success or other numbers if failure
*/

int main(void)
{
	int status, i;
	char *buf = NULL;
	char **argv = NULL;
	pid_t child_pid;
	size_t buf_size = 0;

	/* flag here that will turn to 0 once we see an "exit" input */
	while (1)
	{
		printf("#cisfun$ ");
		/* prompts user for command and arguments */
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

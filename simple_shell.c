#include "shell.h"

/**
 * main - super simple shell
 *
 * Return: 0 upon success
 */
int main(void)
{
	int status, i, is_on;
	char *buf = NULL;
	char **argv = NULL;
	pid_t child_pid;
	size_t buf_size = 0;

	is_on = 1;

	while (is_on)
	{
		/* only prints prompt if interactive mode */
		if (isatty(0) == 1)
			printf("#cisfun$ ");

		/* prompt user for command and handles EOF */
		if (getline(&buf, &buf_size, stdin) == EOF)
		{
			/* doesn't print newline if non-interactive mode */
			if (isatty(0) == 1)
				printf("\n");
			break;
		};

		/* remove newline from string so program can execute*/
		i = strlen(buf);

		/* preserves single characters i.e. '\n' */
		if (i > 1)
		{
			buf[i - 1] = '\0';
		}

		/* create argument vector of CL arguments*/
		argv = split_string(buf);
		if (!argv)
		{
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			exit(0);
		}
		else
		{
			wait(&status);
			if (strcmp(argv[0], "exit") == 0)
			{
				is_on = 0;
			}
		}
	}

	free(argv);
	free(buf);

	return (0);
}

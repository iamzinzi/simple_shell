#include "shell.h"

/**
 * main - super simple shell
 *
 * Return: 0 upon success
 */
int main(int ac __attribute__((unused)), char **av)
{
	int status, i, is_on;
	char *buf = NULL;
	char **argv = NULL;
	pid_t child_pid;
	size_t buf_size = 0;
	int counter = 1;
	char *to_string;

	is_on = 1;
	to_string = malloc(sizeof(char) * 17);

	while (is_on)
	{
		/* only prints prompt if interactive mode */
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		/* prompt user for command and handles EOF */
		if (getline(&buf, &buf_size, stdin) == EOF)
		{
			/* doesn't print newline if non-interactive mode */
			if (isatty(0) == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* remove newline from string so program can execute*/
		i = _strlen(buf);

		/* preserves single characters i.e. '\n' */
		if (i > 1)
		{
			buf[i - 1] = '\0';
		}

		/* create argument vector of CL arguments*/
		argv = split_string(buf);
		/* functionality for spaces */
		if (!argv)
		{
			counter++;
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
			if (execve(argv[0], argv, NULL) == -1)
			{
				if (_strcmp(argv[0], "exit") == 0)
				{
					free(argv);
					break;
				}
				else if (argv[0][0] != '\n')
				{
					counter_to_string(counter, to_string);
					error_helper(
						&av[0], &argv[0], to_string);
			/*		write(STDOUT_FILENO, av[0],
					      _strlen(av[0]));
					write(STDOUT_FILENO,
					      ": ", 2);
					write(STDOUT_FILENO,
					      to_string, _strlen(to_string));
					write(STDOUT_FILENO, ": ", 2);
					write(STDOUT_FILENO, argv[0],
					      _strlen(argv[0]));
					write(STDOUT_FILENO, ": not found\n",
					      12);
			*/	}
				/* free it all before the exit */
				free(to_string);
				free(argv);
			}
			exit(0);
		}
		else
		{
			wait(&status);
			if (_strcmp(argv[0], "exit") == 0)
			{
				is_on = 0;
			}
		}
		counter++;
		free(argv);

	}
	free(buf);
	free(to_string);

	return (0);
}

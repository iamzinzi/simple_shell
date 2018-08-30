#include "shell.h"

/**
 * main - super simple shell
 * @ac: the argument count that we have
 * @av: the array of strings that are our CL arguments
 * Return: 0 upon success
 */

int main(int ac, char **av)
{
	int status, i, is_on;
	int counter = 1;
	int exit_stat = 0;
	size_t too_big = 0;
	char *buf = NULL;
	char *path = _getenv("PATH");
	char *to_string, *full_command = NULL;
	char **argv = NULL;
	pid_t child_pid;
	size_t buf_size = 0;
	list_t *head = NULL;

	/* build linked list of PATH directories */
	build_linked_list(path, &head);
	is_on = 1;
	to_string = malloc(sizeof(char) * 17);
	(void) ac;

	while (is_on)
	{
		/* only prints prompt if interactive mode */
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "$ ", 2);

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
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			/* if doesn't execute: */
			if (_strcmp(argv[0], "exit") == 0)
			{
				free(argv);
				break;
			}
			if (_strcmp(argv[0], "env") == 0)
			{
				print_env();
				free(argv);
				break;
			}
			else if (argv[0][0] != '/')
			{
				counter_to_string(counter, to_string);
				full_command = search_path(head,
					argv[0], av, to_string);
				if (full_command)
					execve(full_command, argv, NULL);
			}
			if (argv[0][0] != '\n' && full_command == NULL)
			{
				counter_to_string(counter, to_string);
				error_helper(
					&av[0], &argv[0], to_string);
				free(to_string);
				exit_stat = 127;
				free(argv);
			}
			exit(exit_stat);
		}
		else
		{
			wait(&status);
			if (_strcmp(argv[0], "exit") == 0)
			{
				is_on = 0;
				if (argv[1])
				{
					counter_to_string(counter, to_string);
					too_big = string_to_int(argv[1]);
					if (too_big > 2147483647
					|| _strlen(argv[1]) > 10)
					{
						exit_helper(&av[0],
						&argv[0], to_string);
						is_on = 1;
						exit_stat = 2;
						continue;
					}
					exit(string_to_int(argv[1]));
				}
			}
			if (full_command)
				free(full_command);
			else
				exit_stat = 127;
		}
		counter++;
		free(argv);

	}
	free_list(head);
	free(buf);
	free(to_string);

	return (exit_stat);
}

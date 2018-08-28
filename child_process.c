#include "shell.h"

/**
* child_process - this function handles the child process
* @child_pid: the child pid integer that was forked
* @av: the shell argument that is passed aka ./hsh
* @argv: the arguments that are passed so eveerything in the shell prompt
* @head: the linked list head node
* @to_string: a string that we will use as a buffer
* @full_command: the entire absolute PATH of the command
*
* Description: this part handles all things that have to do with children
* Return: returns 1 if error, if not then it will exit
*/

int child_process(int child_pid, char **av, char **argv, 
	list_t *head, int counter, char *to_string, char *full_command)
{
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
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
			break;
		}
		else if (argv[0][0] != '/')
		{
			full_command = search_path(head,
						   argv[0]);
			if (full_command)
				execve(full_command, argv, NULL);
		}
		if (argv[0][0] != '\n' && full_command == NULL)
		{
			counter_to_string(counter, to_string);
			error_helper(
				&av[0], &argv[0], to_string);
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
			if (argv[1])
			{
				exit(string_to_int(argv[1]));
			}
		}
		if (full_command)
			free(full_command);
	}
}

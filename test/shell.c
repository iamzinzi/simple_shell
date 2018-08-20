#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int word_count(char *str);
char **split_string(char *str);
void free_array_of_words(char **arr);

/**
 * main - super simple shell
 *
 * Return: 0 upon success
 */
int main(void)
{
	int status, i;
	char *buf;
	char **argv;
	pid_t child_pid;
	size_t buf_size = 0;

	while (1)
	{
		printf("#cisfun$ ");
		/* prompt user for command */
		getline(&buf, &buf_size, stdin);
		/* create argument vector of CL arguments*/
		argv = split_string(buf);

		for (i = 0; argv[i] != NULL; i++)
			printf("argv[%d]: %s\n", i, argv[i]);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("%u\n", getpid());
			execve(argv[0], argv, NULL);
			printf("lol\n");
		}
		else
		{
			wait(&status);
			free_array_of_words(argv);
			free(argv);
			free(buf);
		}
	}

	return (0);
}

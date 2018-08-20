#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - executes the command ls -l /tmp in 5 different child processes
 *
 * Return - 0 on success
 */
int main(void)
{
	int i, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", ".", NULL};

	for (i = 0; i < 5; i++)
	{
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
			printf("test%d\n", i);
		}
	}
	return (0);
}

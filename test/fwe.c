#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - executes the command ls -l /tmp in 5 different child processes
*
* Description: each child is created by the same parent and we must
*	wait for a child to exit before creating a new child
* Return: 0 on success
*/

int main(void)
{
	int i, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", ".", NULL};

	/* loop 5 times, make 5 forks or 5 children, */
	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		/* if process is a child then execute */
		if (child_pid == 0)
		{
			sleep(1);
			execve(argv[0], argv, NULL);
		}
		else/* once we are done with the child we print test */
		{
			wait(&status);
			printf("Test: %d\n\n\n", i);
		}
	}
	return (0);
}

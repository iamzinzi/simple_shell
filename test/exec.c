#include <stdio.h>
#include <unistd.h>

/**
* main - example of execve
*
* Return: 0 if success.
*/

int main(void)
{
	/* test the exec file by finding the ls exe in the bin */
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	/* if the execve call returned a -1, that is an error*/
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error:");
	printf("After execve\n");
	return (0);
}

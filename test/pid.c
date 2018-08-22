#include <stdio.h>
#include <unistd.h>

/**
* main - will get the PID of the current process
*
* Description: uses a system call to retrieve the PID
* Return: 0 is successful or other if error
*/

int main(void)
{
	/* The pid_t data type is a signed int */
	pid_t my_pid;
	/* getpid will return the process ID of the current process*/
	my_pid = getpid(void);
	printf("%u\n", my_pid);
	return (0);
}

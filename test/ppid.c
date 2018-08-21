#include <stdio.h>
#include <unistd.h>

/**
* main - function that gets the perent PID of the current process
*
* Description: uses the getppid system call to get an signed int
* Return: Always 0.
*/

int main(void)
{
	/* pid_t is an signed int data type */
	pid_t my_ppid;
	/* getppid will return the parent PID of the current process */
	my_ppid = getppid(void);
	printf("%u\n", my_ppid);
	return (0);
}

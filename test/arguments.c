#include <stdio.h>

/**
* main - prints all arguments without using ac
* @argc: the number of arguments. This will not be used
* @argv: the values of each argument stored as a string
*
* Description: must make the argc void or unused attribute
* Return: Always 0
*/

int main(int argc __attribute__((unused)), char *argv[])
{
	/* Start at 1 since 0 is the command and not arguments */
	int i = 0;
	/* print each argv string until it is a null term*/
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}

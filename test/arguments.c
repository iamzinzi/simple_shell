#include <stdio.h>

/**
 * main - prints all arguments without using ac
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int i = 1;

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}

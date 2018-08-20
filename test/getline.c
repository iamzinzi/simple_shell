#include <stdio.h>
#include <stdlib.h>

/**
 * main - sends prompt
 *
 * Return: 0
 */
int main(void)
{
	char *buf;
	size_t buf_size = 0;

//	buf = malloc(sizeof(char) * buf_size);
//	if (!buf)
//		exit(1);
	printf("$ ");

	getline(&buf, &buf_size, stdin);
	printf("%s", buf);
	free(buf);
	return (0);
}

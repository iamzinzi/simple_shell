#include <stdio.h>
#include <stdlib.h>

/**
* _getline - our own version of getline
* @buf: the buffer we will send the address to
* @n: the size of the input
* @stream: where we obtain the data, usually stdin
*
* Description: works similar to the getline
* Return: the number of chars
*/

int _getline(char **buf, size_t *n, FILE *stream)
{
	unsigned int bufp;
	unsigned int count = 0;
	int c;

	/* getc obtains each character from the stream location */
	for (bufp = 0; (c = getc(stream)) != EOF && c != '\n' && bufp < *n; bufp++)
	{
		(*buf)[bufp] = c;
		count++;
	}
	/* if a new line was found, we skip it! */
	if (c == '\n')
	{
		(*buf)[bufp++] = c;
		count++;
	}

	/* we add the null byte and return how many characters there were*/
	(*buf)[bufp] = '\0';

	return (count);
}

/**
* main - the main function, used to test our getline function
*
* Description: see man 3 getline for similar info
* Return: Returns 0 if successful or 1 if not
*/

int main(void)
{
	/* declare variables, initialize buf_size to hold a nice number */
	char *buf;
	size_t buf_size = 1024;
	int count;

	/* malloc space for the buffer,.. if it fails return 1 */
	buf = malloc(sizeof(char) * buf_size);
	if (!buf)
		exit(1);
	printf("$ ");

	count = _getline(&buf, &buf_size, stdin);
	printf("%s", buf);
	printf("%d characters read\n", count);
	free(buf);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

/**
* main - prints $ and waits for user input, then prints the input via buffer
*
* Description: after user inputs, we print that onto the next line
*	getline returns the number of chars read or -1 on failure.
*	common prototype is usually:
*	ssize_t getline(char **lineptr, size_t *n, FILE *stream);
* Return: 0 on success or something else if it fails
*/

int main(void)
{
	/* buf is our buffer that will store the address */
	/* our buffersize which initalize with 0 but can hold up to size_t */
	char *buf;
	size_t buf_size = 0;

/*
* This code block is not needed since getline handles
* malloc, buffers, and exit if errors
*
* buf = malloc(sizeof(char) * buf_size);
* if (!buf)
*	exit(1);
*
* the buffer is null term'd and includes a newline char if included
*/

	/* We print a $ then wait for a user input line, using buffers */
	/* Print the buffer then free the buffer that we used*/
	printf("$ ");
	getline(&buf, &buf_size, stdin);
	printf("%s", buf);
	free(buf);
	return (0);
}

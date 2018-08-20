#include <stdio.h>
#include <stdlib.h>

int _getline(char **buf, size_t *n, FILE *stream)
{
	unsigned int bufp, count = 0;
	int c;

	for (bufp = 0; (c = getc(stream)) != EOF && c != '\n' && bufp < *n; bufp++)
	{
		(*buf)[bufp] = c;
		count++;
	}

	if (c == '\n')
	{
		(*buf)[bufp++] = c;
		count++;
	}


	(*buf)[bufp] = '\0';

	return (count);
}

int main(void)
{
        char *buf;
        size_t buf_size = 1024;
	int count;

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

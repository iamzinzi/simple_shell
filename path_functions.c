#include "shell.h"

/**
 * _strstr - locate a substring
 * @haystack: string to be looked through
 * @needle: substring to be searched for in haystack
 *
 * Return: first occurence of the substring needle in haystack,
 * or NULL is substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, needle_len, match_len;
	char *substring = NULL;

	needle_len = 0;
	for (i = 0; needle[i] != '\0'; i++)
		;
	needle_len = i;

	if (needle_len == 0)
		return (haystack);

	match_len = 0;
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i] != needle[j])
			{
				if (match_len > 0 && substring)
				{
					substring = NULL;
					match_len = 0;
				}
				else
					continue;
			}
			if (haystack[i] == needle[j])
			{
				if (substring == NULL)
					substring = &haystack[i];
				i++;
				match_len++;
			}
		}
		if (match_len == needle_len)
			return (substring);
	}
	return (substring);
}

char *_getenv(const char *name)
{
	int i;
	char *token;

	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], (char *)name))
		{
			token = strtok(environ[i], "=");
			token = strtok(NULL, "=");
		}
	}
	return (token);
}

int main()
{
	char *path = _getenv("PATH");
	printf("%s\n", path);
	return (0);
}

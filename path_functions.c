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

/**
 * _getenv - get an environment variable
 * @name: name of environment variable to look for
 *
 * Return: pointer to the value in the environment
 * or NULL if there is no match
 */
char *_getenv(const char *name)
{
	int i;
	char *token = NULL;

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

/**
 * add_node_end - adds a new node at the end of a `list_t` linked list
 * @head: pointer to first node in linked list
 * @str: string to be assigned to new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		for (i = *head; i->next != NULL; i = i->next)
			;
		i->next = new;
	}
	return (new);
}

/**
 * build_linked_list - builds a linked list
 * @path: pointer to value of environment variable PATH
 * @head: pointer to pointer to head of a linked list
 */
void build_linked_list(char *path, list_t **head)
{
	char *token;

	token = strtok(path, ":");
	while (token)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}

/* this is a function to test/prove that the above functions work */
int main(void)
{
	list_t *head, *node;
	char *path = _getenv("PATH");

	head = NULL;
	build_linked_list(path, &head);

	for (node = head; node != NULL; node = node->next)
	{
		printf("%s\n", node->str);
	}
	return (0);
}

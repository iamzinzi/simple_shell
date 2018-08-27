#include "shell.h"

char *search_path(list_t *head, char *c)
{
	list_t *node;
	struct stat buf;
	char *full_command;
	char *command = str_concat("/", c);

	for (node = head; node != NULL; node = node->next)
	{
		full_command = str_concat(node->str, command);
		if (stat(full_command, &buf) == 0)
			return (full_command);
		free(full_command);
	}
	return (NULL);
}

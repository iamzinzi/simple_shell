#include "shell.h"

char *search_path(list_t *head, char *c)
{
	list_t *node;
//	struct stat buf;
	char *full_command;
	char *command = str_concat("/", c);

	for (node = head; node != NULL; node = node->next)
	{
		full_command = str_concat(node->str, command);
	//	if (stat(full_command, &buf) == 0)
	//		return (full_command);
		if (access(full_command, X_OK) == 0)
			return (full_command);
//		if (stat(full_command, &buf) == 0)
//		{
//			if (access(full_command, X_OK) == -1)
//			{
//GET THIS TO WORK		write(1,"NOT FOUND", 9);
//			}
//		}
		free(full_command);
	}
	free(command);
	return (NULL);
}

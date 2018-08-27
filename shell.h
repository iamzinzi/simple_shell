#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

extern char **environ;

int _strlen(char *s);
int word_count(char *str);
int _strcmp(char *s1, char *s2);
char **split_string(char *str);
char *counter_to_string(int i, char *to_string);
char *_strstr(char *haystack, char *needle);
char *_getenv(const char *name);
void error_helper(char **av, char **argv, char *to_string);
list_t *add_node_end(list_t **head, const char *str);
void build_linked_list(char *path, list_t **head);
void free_list(list_t *head);

#endif /* _SHELL_H_ */

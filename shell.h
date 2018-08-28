#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
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

void print_env(void);
void free_list(list_t *head);
void build_linked_list(char *path, list_t **head);
void error_helper(char **av, char **argv, char *to_string);

int _strlen(char *s);
int word_count(char *str);
int string_to_int(char *s);
int _strcmp(char *s1, char *s2);

char *_strdup(char *s);
char **split_string(char *str);
char *_getenv(const char *name);
char *str_concat(char *s1, char *s2);
char *search_path(list_t *head, char *c);
char *_strstr(char *haystack, char *needle);
char *counter_to_string(int i, char *to_string);

list_t *add_node_end(list_t **head, char *str);

#endif /* _SHELL_H_ */

#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strlen(char *s);
int word_count(char *str);
int _strcmp(char *s1, char *s2);
char **split_string(char *str);
char *counter_to_string(int i, char *to_string);
char *_strstr(char *haystack, char *needle);
char *_getenv(const char *name);
void error_helper(char **av, char **argv, char *to_string);

#endif /* _SHELL_H_ */

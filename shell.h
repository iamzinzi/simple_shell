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
char **split_string(char *str);
char *counter_to_string(int i, char *to_string);

#endif /* _SHELL_H_ */

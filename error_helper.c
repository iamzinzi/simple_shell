#include "shell.h"

/**
* error_helper - helps write all the errors
* @av: the av[0] passed to us
* @argv: thr argv[0] that is passed to us
* @to)string- the string that we want to be printed
*
* Description: so we want to print out erros with first,
*	we want the path av[0] printed first followed by
*	a ": " followed by the line number
*	followed by the another ": " and then
*	followed by the command string argv[0]
*	then we want to print out a
*	": not found". cause its always an error in this function
*	we moved 6 write functions from main to here
* Return: no return it is void
*/

void error_helper(char **av, char **argv, char *to_string)
{
	write(STDOUT_FILENO, av[0], _strlen(av[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, to_string, _strlen(to_string));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

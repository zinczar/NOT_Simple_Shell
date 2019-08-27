#include "shell.h"

/**
 * special_chars - entry point
 * @buffer:
 *
 * Return: 0
 */

int special_chars(char *argv, char *argv1, int status)
{

	if (_strcmp(argv, "exit") == 0)
	{
		free(argv);
		exit(status);
	}
	if (_strcmp(argv, "env") == 0)
	{
		_printenv();
		return (0);
	}

	if (_strcmp(argv, "cd") == 0)
	{
		chdir(argv1);
		return (0);
	}

/*	if (_strcmp(argv, "echo $?") == 0)
	{
		perror(buffer);
		return (-1);
		}*/
	return (-1);
}

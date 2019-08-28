#include "shell.h"

/**
 * special_chars - entry point
 * @argv: The primary command
 * @argv1: Flag or path
 * @status: Exit status
 *
 * Return: 0 on success, -1 on failure
 */

int special_chars(char *argv, char *argv1)
{

	if (_strcmp(argv, "exit") == 0)
	{
		free(argv);
		exit(EXIT_SUCCESS);
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

	return (-1);
}

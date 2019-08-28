#include "shell.h"

/**
 * *_getenv - gets environment
 * @name: section of env to return
 *
 * Return: env matching parameter
 */

char *_getenv(char *name)
{
	size_t i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		return (&environ[i][_strlen(name)]);
	}
	return (NULL);
}
/**
 * _printenv - prints the environment
 *
 * Return: Always 0.
 */
int _printenv(void)
{
	size_t i, j;

	for (j = 0; environ[j]; j++)
	{
		for (i = 0; environ[j][i]; i++)
			_putchar(environ[j][i]);
		_putchar('\n');
	}
	return (0);
}

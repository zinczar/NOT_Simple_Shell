#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if strings are equal. <0 if S2 is greater. >0 if S1 is greater
 *
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * print_cwd - Prints CWD
 * @cwd: CWD Path
 *
 * Return: 0
 */

void print_cwd(char *cwd)
{
	int i = 0;

	while (cwd[i])
		_putchar(cwd[i++]);
	_putchar('$');
	_putchar(' ');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * error_print - compares two strings
 * @argv0: Command argument
 * @count: Shell iterations 
 *
 * Return: Prints errors
 *
 */
void error_print(char *argv0, int count)
{
	write(STDIN_FILENO, "./hsh:", 21);
	write(STDIN_FILENO, count, _strlen(count));
	write(STDIN_FILENO, ":", 2);
	write(STDIN_FILENO, argv0, _strlen(argv0));
	write(STDIN_FILENO, ": not found", 12);
}

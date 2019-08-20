#include "shell.h"

/**
 * _strlen - code
 * @s: Char
 *
 * Return: Count
 */
int _strlen(const char *s)
{
	int count = 0;

	while (s[count])
	{
		count++;
	}
	return (count);
}

/**
 * _strcpy - Code
 * @dest: Char
 * @src: Char
 *
 * Return: Dest
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int src_len, i;

	src_len = _strlen(src);

	for (i = 0; i < src_len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - check the code for Holberton School students.
 * @dest: Char
 * @src: Char
 *
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int strlen = 0;
	int i;

	while (*dest)
	{
		strlen++;
		dest++;
	}

	for (i = 0 ; src[i] != '\0' ; i++)
	{
		dest[(strlen - 1) + i] = src[i];
	}
	dest[i + 1] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: string 1
 *
 * @s2: string 2
 *
 * Return: compared strings
 *
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

int _strncmp(char *str1, char *str2, int n)
{
	int count = 0, i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			count = count + 1;
	}
	return (count);
}

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

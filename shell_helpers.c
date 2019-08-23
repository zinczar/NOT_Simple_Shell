#include "shell.h"

/**
 * _strlen - Determines the number of characters in a string
 * @s: The string to be counted
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
 * _strcpy - A function that copies a string into pre-allocated memory
 * @dest: Copy of the string
 * @src: String to copy
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
	int length = _strlen(dest);
	int i = 0;

	while (src[i])
	{
		dest[length] = src[i];
		length++;
		i++;
	}
	dest[length] = '\0';

	return (dest);
}

/**
 * _strncmp - compares strings upto n length
 * @str1: first string to be compared
 * @str2: second string to be compared
 * @n: Maximum number of bytes to comapre
 *
 * Return: number of differences between the strings
 */

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

/**
 * _strdup - gets environment
 * @string: Incoming string to duplicate
 *
 * Return: a ptr to a null-terminated string, which is a duplicate of string
 */

char *_strdup(char *string)
{
	char *duplicate;
	size_t i = 0, length = 0;

	if (string == NULL)
		return (NULL);

	length = _strlen(string);

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[i] = string[i]) != '\0')
		i++;

	return (duplicate);
}

#include "shell.h"

int main(void)
{
	char *string1 = "apple";
	char *string2 = "apple";
	int comp;

	comp = _strcmp(string1, string2);

	printf("%i\n", comp);
	return (0);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: compared strings
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

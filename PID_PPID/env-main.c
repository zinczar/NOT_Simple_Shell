#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i = 0, j;

	while (env[i] != NULL)
	{
		printf("env while loop:%s\n", env[i]);
		printf("env Address: %p\n", &env);
		i++;
	}
	for (j = 0; environ[j]; j++)
	{
		printf("Environ For Loop: %s\n", environ[j]);
                printf("Environ Address: %p\n", &environ);
	}
	return (0);
}

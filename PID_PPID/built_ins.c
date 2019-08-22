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
 * @ac: Not Used
 * @av: Not used
 * @env: Location of system environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	size_t i = 0;

	(void)ac;
	(void)av;
	while (env[i])
		printf("%s\n", env[i++]);
	return (0)
}

#include <stdio.h>

int main(int ac, char **av, char **env)
{
	size_t i = 0;

	(void)ac;
	(void)av;

	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}

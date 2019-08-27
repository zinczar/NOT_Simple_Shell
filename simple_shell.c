#include "shell.h"

/**
 * main - Simple Shell
 *
 * Return: 0
 */

int main(void)
{	int i, status = 0;
	char *buffer = NULL;
	char *command_token = NULL, *command_array[100], *exe_token = NULL;
	size_t bufsize = 32;
	ssize_t characters;
	pid_t child_pid;
	char cwd[PATH_MAX];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDIN_FILENO, "ᕙ(⇀‸↼‶)ᕗ  ", 21);
		getcwd(cwd, sizeof(cwd));
		print_cwd(cwd);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
			break;
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';
		command_token = strtok(buffer, " ");
		i = 0;
		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;
		if (special_chars(command_array[0], command_array[1], status) == 0)
			continue;
		child_pid = fork();
		if (childcare(child_pid, exe_token, command_array) > 0)
			waitpid(child_pid, &status, WUNTRACED);
	}
	free(buffer);
	buffer = NULL;
	return (0);
}

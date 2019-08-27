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
		write(STDIN_FILENO, "$ ", 3);
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
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			exe_token = pathfinder(command_array[0]);
			if (execve(exe_token, command_array, NULL) == -1)
			{
				perror(exe_token);
				exit(1);
			}
		}
		else if (child_pid > 0)
			waitpid(child_pid, &status, WUNTRACED);
	}
	free(buffer);
	buffer = NULL;
	return (0);
}

#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	int i, status;
	char *buffer = NULL;
	char *command_token;
	char *command_array[100];
	size_t bufsize = 32;
	ssize_t characters;
	pid_t child_pid;
	char *exe_token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDIN_FILENO, "ᕙ(⇀‸↼‶)ᕗ $ ", 23);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
			break;
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';
		if (_strcmp(buffer, "exit") == 0)
			return (2);
		if (_strcmp(buffer, "env") == 0)
			_printenv();
		command_token = strtok(buffer, " ");
		i = 0;
		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;
		if (_strcmp(command_array[0], "cd") == 0)
		{
			chdir(command_array[1]);
			continue;
		}
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
				perror(exe_token);
		}
		else if (child_pid > 0)
			waitpid(child_pid, &status, WUNTRACED);
	}
	free(buffer);
	return (0);
}

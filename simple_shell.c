#include "shell.h"

int main(void)
{
	int i = 0;
	char *buffer = NULL;
	char *command_token;
	char *command_array[100];
	size_t bufsize = 32;
	size_t characters;
	pid_t child_pid;
	int status;
	char *exe_token = NULL;

	while (1)
	{
		i = 0;
		write(STDIN_FILENO,"ᕙ(⇀‸↼‶)ᕗ $ ", 23);
		characters = getline(&buffer,&bufsize,stdin);
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';

		command_token = strtok(buffer, " ");

		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;

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
				perror("Could not execve");
		}
		else if (child_pid > 0)
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
	}
	return(0);
}

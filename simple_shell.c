#include "shell.h"

int main(void)
{
	int i = 0, j = 0;
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
		printf("BUFFER:[%s]\n", buffer);
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';
		printf("BUFFER:[%s]\n", buffer);

		command_token = strtok(buffer, " ");

		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;

		while (command_array[j])
			printf("[%d]: %s\n", j, command_array[j]), j++;
		j = 0;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			printf("### Child ###\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);
			printf("%lu characters were read.\n",characters);
			exe_token = pathfinder(command_array[0]);
			printf("exe_token:%s\n", exe_token);
			if (execve(exe_token, command_array, NULL) == -1)
				perror("Could not execve");
			printf("PATH: %s\n", exe_token);
		}
		else if (child_pid > 0)
		{
			waitpid(child_pid, &status, WUNTRACED);
			printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",getpid(), child_pid);
		}
	}

	free (buffer);

	return(0);
}

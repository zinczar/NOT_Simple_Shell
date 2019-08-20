#include "shell.h"

int main(void)
{
	int i = 0, j = 0;
	char *buffer;
	char *command_token;
	char *command_array[100];
	size_t bufsize = 32;
	size_t characters;
	pid_t child_pid;
	int status;
	char *exe_token;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		write(STDIN_FILENO,"ᕙ(⇀‸↼‶)ᕗ $ ", 23);
		characters = getline(&buffer,&bufsize,stdin);

		command_token = strtok(buffer, " ");

		while (command_token != NULL)
		{
			command_array[i++] = command_token;
			command_token = strtok(NULL, " ");
		}
		command_array[i] = NULL;

		while (command_array[j])
			printf("%s\n", command_array[j++]);

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

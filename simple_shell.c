#include "shell.h"

int main(void)
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	pid_t child_pid;
	int status;
	char *test_path = _getenv("PATH");

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
			printf("You typed: '%s'\n",buffer);
			printf("PATH: %s\n", test_path);
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

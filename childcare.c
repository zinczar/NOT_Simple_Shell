#include "shell.h"

/**
 * childcare - Dealing with child process
 * @child_pid: Child PID
 * @exe_token: Executable path
 * @command_array: Array of commands
 * Return: 0
 */

int childcare(pid_t child_pid, char *exe_token, char **command_array)
{
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
/*			error_print();*/
			perror(exe_token);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
		return (child_pid);
	return (0);
}

/**
 * error_print - compares two strings
 * @argv0: Command argument
 * @count: Shell iterations
 *
 * Return: Prints errors
 *
 */
/*void error_print(void)
{
	write(STDERR_FILENO, "./hsh:", 21);
	write(STDERR_FILENO, "1", 2);
	write(STDERR_FILENO, ":", 2);
	write(STDERR_FILENO, "GARBAGE", 8);
	write(STDERR_FILENO, ": not found", 12);
        write(STDERR_FILENO, "\n", 2);
	}*/

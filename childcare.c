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
			perror(exe_token);
			exit(127);
		}
	}
	else if (child_pid > 0)
		return (child_pid);
	return (0);
}

#include "shell.h"

/**
 * execute_command - Forks and executes a command
 * @args: command and arguments
 * @prog: program name
 */
void execute_command(char **args, char *prog)
{
	char *cmd = args[0], *full_path;
	struct stat st;
	pid_t child_pid;

	if (strchr(cmd, '/'))
		full_path = strdup(cmd);
	else
		full_path = get_path(cmd);

	if (!full_path)
	{
		write(STDERR_FILENO, prog, strlen(prog));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, cmd, strlen(cmd));
		write(STDERR_FILENO, ": not found\n", 13);
		_exit(127);
	}

	if (stat(full_path, &st) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(full_path, args, environ);
			perror(prog);
			free(full_path);
			_exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	free(full_path);
}

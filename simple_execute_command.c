#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * simple_execute_command - Execute command
 * @args: tableau d'arguments
 */
void simple_execute_command(char **args)
{
	char *full_cmd = NULL;
	pid_t pid;
	int status;

	if (!args || !args[0])
		exit(0);

	full_cmd = strdup(args[0]);

	if (!full_cmd)
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_cmd, args, environ);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(full_cmd);
	}
}

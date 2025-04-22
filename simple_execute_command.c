#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * simple_execute_command - Execute command
 * @args: tableau d'arguments
 * Return: exit value
 */
int simple_execute_command(char **args)
{
	char *full_cmd = NULL;
	pid_t pid;
	int status, exist_cmd = 0, do_fork = 1;

	if (!args || !args[0]) /* if args == NULL or args[0] == NULL => exit(0) */
		return (0);
	if (strchr(args[0], '/'))
		full_cmd = strdup(args[0]);
	else
		full_cmd = search_path(args[0]);
	if (full_cmd != NULL)
		exist_cmd = exist_command(full_cmd);
	/* check if command dont be found or command not exist and not executable */
	if (full_cmd == NULL || exist_cmd == 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(full_cmd);
		do_fork = 0;
	}
	if (do_fork == 1)
	{
		pid = fork();
		if (pid == -1) /* if the fork fail launch error */
		{
			perror("fork");
			free(full_cmd);
			return (2);
		}
		if (pid == 0) /* Processus child => exec command */
		{
			execve(full_cmd, args, environ);
			perror("execve");
			free(full_cmd);
			return (2);
		}
		/* Parent : wait for child */
		waitpid(pid, &status, 0);
		free(full_cmd); /* free pointer */
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (2);
	}
	else
		return (127);
}

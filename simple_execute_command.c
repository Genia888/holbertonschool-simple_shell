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
		pid = fork(); /* fork the process */
		if (pid == -1)
		{
			perror("fork");
			free(full_cmd);
			return (2);
		}
		if (pid == 0) /* Processus enfant */
		{
			execve(full_cmd, args, environ);
			perror("execve");
			free(full_cmd);
			return (2);
		} /* Parent : attendre la fin du processus enfant */
		waitpid(pid, &status, 0);

		free(full_cmd); /* Retourner le code de sortie du processus enfant */
		if (WIFEXITED(status))
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			printf("plop %d\n", status);
			return (WEXITSTATUS(status));
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			printf("plop2 %d\n", status);
			return (2);

		}
	}
	else
	{
		return (127);
	}
}

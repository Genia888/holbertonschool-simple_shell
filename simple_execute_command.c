#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * free_str - free a string
 * @flag: flag
 * @str: strig to free
 */
void free_str(int flag, char *str)
{
	if (flag)
		free(str);
}


/**
 * simple_execute_command - Execute command
 * @args: tableau d'arguments
 * Return: exit value
 */
int simple_execute_command(char **args)
{
	char *full_cmd = NULL;
	pid_t pid;
	int status, exist_cmd = 0, flag = 0;

	if (!args || !args[0]) /* if args == NULL or args[0] == NULL => exit(0) */
		return (0);
	if (strchr(args[0], '/'))
	{
		full_cmd = strdup(args[0]);
		flag = 1;
	}
	else
		full_cmd = search_path(args[0]);
	exist_cmd = exist_command(full_cmd);
	/* if we cannot allocate memory display an error message */
	if (!full_cmd || !exist_cmd)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}
	pid = fork(); /* fork the process */
	if (pid == -1)
	{
		perror("fork");
		free_str(full_cmd);
		return (2);
	}
	if (pid == 0) /* Processus enfant */
	{
		execve(full_cmd, args, environ);
		perror("execve");
		free_str(flag, full_cmd);
		return (2);
	} /* Parent : attendre la fin du processus enfant */
	waitpid(pid, &status, 0);
	free_str(full_cmd); /* Retourner le code de sortie du processus enfant */
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (2);
}

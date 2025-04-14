#include "shell.h"

/**
 * execute_command - Fork and execute if command exists
 * @args: command + args
 * @prog: argv[0] (shell name)
 */
void execute_command(char **args, char *prog)
{
	char *cmd = args[0], *full_path = NULL;
	pid_t child_pid;
	struct stat st;

	if (stat(cmd, &st) == 0)
		full_path = strdup(cmd);
	else
		full_path = get_path(cmd);

	if (!full_path)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", prog, cmd);
		return;
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(full_path, args, environ);
		perror(prog);
		exit(127);
	}
	else
		wait(NULL);

	free(full_path);
}

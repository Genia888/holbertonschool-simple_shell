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
	int exist_cmd = 0;
	/* if args == NULL or args[0] == NULL => exit(0) */
	if (!args || !args[0])
		exit(0);
	/* duplicate the args[0] or search path */
	if (strchr(args[0], '/'))
	{
		full_cmd = strdup(args[0]);
		exist_cmd = exist_command(full_cmd);
	}
	else
	{
		full_cmd = search_path(args[0]);
		exist_cmd = exist_command(full_cmd);
	}
	/* if we cannot allocate memory display an error message */
	if (!full_cmd)
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}
	/* if we cannot allocate memory display an error message */
        if (!exist_cmd)
        {
                dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
                exit(127);
        }
	/* fork the process */
	pid = fork();
	if (pid == 0)
	{
		/* system to to the program content in full_cmd variable */
		execve(full_cmd, args, environ);
		/* display the error message if there are one */
		/* normaly the function will be exit before that */
		perror("execve");
		/* end of the parent process */
		exit(1);
	}
	else
	{
		/* wait the parent process */
		waitpid(pid, &status, 0);
		/* free the strdup allocation */
		free(full_cmd);
	}
}

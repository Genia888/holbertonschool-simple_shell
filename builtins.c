#include "shell.h"

/**
 * handle_builtin - Handles exit and env
 * @args: command and args
 * Return: 0 if builtin handled, 1 otherwise
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
			printf("%s\n", *env++);
		return (0);
	}
	return (1);
}

#include "shell.h"

/**
 * free_args - Frees memory of arguments
 * @args: null-terminated array
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
		free(args[i++]);
	free(args);
}

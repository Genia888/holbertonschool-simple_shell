#include "shell.h"

/**
 * get_path - Searches for command in PATH
 * @cmd: command
 * Return: full path or NULL
 */
char *get_path(char *cmd)
{
	char *path = getenv("PATH"), *dir, *full;
	struct stat st;

	if (!path)
		return (NULL);

	path = strdup(path);
	dir = strtok(path, ":");

	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			break;

		sprintf(full, "%s/%s", dir, cmd);
		if (stat(full, &st) == 0)
		{
			free(path);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

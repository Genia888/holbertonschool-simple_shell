#include "shell.h"

/**
 * _getenv - Gets value of an env variable
 * @name: env var name
 * Return: pointer to value or NULL
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * get_path - Searches for command in PATH
 * @cmd: command
 * Return: full path or NULL
 */
char *get_path(char *cmd)
{
	char *path, *token, *full;
	struct stat st;

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path = strdup(path);
	token = strtok(path, ":");
	while (token)
	{
		full = malloc(strlen(token) + strlen(cmd) + 2);
		if (!full)
			break;

		sprintf(full, "%s/%s", token, cmd);
		if (stat(full, &st) == 0)
		{
			free(path);
			return (full);
		}
		free(full);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

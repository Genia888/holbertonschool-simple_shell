#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * exist_command - test if the command exists
 * @cmd : name of the exec
 *
 * Return: if the command exists
 */
int exist_command(char *cmd)
{
	struct stat st;

	if (stat(cmd, &st) == 0 && access(cmd, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * search_path - Recherche une commande dans le PATH
 * @cmd: commande (ex: "ls")
 * Return: chemin complet (à free) ou NULL si non trouvée
 */

char *search_path(char *cmd)
{
	char *path = NULL, *path_copy, *token, *full_path;
	struct stat st;
	int i;

	/* find the environnement variable for the path */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	token = strtok(path_copy, ":"); /* split the path by : */
	while (token)
	{
		/* allocate the memory for the path directory */
		full_path = malloc(strlen(token) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		/* check if the file exist and if we can exec it */
		if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		} /* free the full path */
		free(full_path);
		token = strtok(NULL, ":");
	} /* if the the full path have not been found free it */
	free(path_copy);
	return (NULL);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

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

    token = strtok(path_copy, ":");
    while (token)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        sprintf(full_path, "%s/%s", token, cmd);
        if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}

#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

char *_which(char *cmd, char **environ)
{
    char *copy = NULL, *token = NULL, *full_path = NULL;
    struct stat st;
    int i;

    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            copy = strdup(environ[i] + 5);
            break;
        }
    }
    if (!copy)
        return (NULL);

    token = strtok(copy, ":");
    while (token)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (!full_path)
        {
            free(copy);
            return (NULL);
        }

        sprintf(full_path, "%s/%s", token, cmd);

        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(copy);
            return (full_path);
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(copy);
    return (NULL);
}

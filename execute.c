#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int execute_command(char **argv, char **environ)
{
    pid_t pid;
    int status;
    char *full_path = NULL;

    if (!argv || !argv[0])
        return (0);

    /* Chemin absolu ou relatif */
    if (argv[0][0] == '/' || argv[0][0] == '.')
    {
        if (access(argv[0], X_OK) != 0)
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
            return (127);
        }

        pid = fork();
        if (pid == 0)
        {
            execve(argv[0], argv, environ);
            perror("execve");
            exit(1);
        }
        wait(&status);
        return (WEXITSTATUS(status));
    }

    /* Sinon on cherche via PATH */
    full_path = _which(argv[0], environ);
    if (!full_path || access(full_path, X_OK) != 0)
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        if (full_path)
            free(full_path);
        return (127);
    }

    pid = fork();
    if (pid == 0)
    {
        execve(full_path, argv, environ);
        perror("execve");
        free(full_path);
        exit(1);
    }
    free(full_path);
    wait(&status);
    return (WEXITSTATUS(status));
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Exécute une commande
 * @args: tableau d'arguments
 */
void execute_command(char **args)
{
    char *full_cmd = NULL;
    pid_t pid;

    if (!args || !args[0])
        return;

    if (strchr(args[0], '/'))
    {
        full_cmd = strdup(args[0]);
    }
    else
    {
        full_cmd = search_path(args[0]);
        if (!full_cmd)
        {
            dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
            exit(127);
        }
    }

    pid = fork();
    if (pid == 0)
    {
        execve(full_cmd, args, environ);
        perror("execve");
        exit(1);
    }
    else
    {
        wait(NULL);
    }

    free(full_cmd);
}

/**
 * main - Shell minimal
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL, *token = NULL, *args[10];
    size_t len = 0;
    int i;

    while (getline(&line, &len, stdin) != -1)
    {
        i = 0;
        token = strtok(line, " \t\n");
        while (token && i < 9)
        {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        if (args[0])
            execute_command(args);
    }

    free(line);
    return (0);
}

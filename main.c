#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av, char **environ)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    char *argv[64];
    int i, status = 0;

    (void)ac;
    (void)av;

    write(STDOUT_FILENO, "$ ", 2);
    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        free(line);
        return (0);
    }

    token = strtok(line, " \n");
    i = 0;
    while (token && i < 63)
    {
        argv[i++] = token;
        token = strtok(NULL, " \n");
    }
    argv[i] = NULL;

    status = execute_command(argv, environ);
    free(line);
    return (status);
}

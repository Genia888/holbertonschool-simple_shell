#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *name);
char *trim_spaces(char *str);
char **parse_line(char *line);
void free_args(char **args);
char *get_path(char *cmd);
int execute_command(char **argv, char **environ);
int handle_builtin(char **args);

#endif
char *_which(char *cmd, char **environ);

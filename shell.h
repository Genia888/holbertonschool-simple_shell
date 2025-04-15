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
void execute_command(char **args, char *prog);
int handle_builtin(char **args);

#endif

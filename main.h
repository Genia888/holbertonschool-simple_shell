#ifndef MAIN_H
#define MAIN_H

char *search_path(char *cmd);
void execute_command(char **args);
extern char **environ;

#endif

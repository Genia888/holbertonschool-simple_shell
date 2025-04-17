#ifndef MAIN_H
#define MAIN_H

int exist_command(char *cmd);
char *search_path(char *cmd);
void simple_execute_command(char **args);
extern char **environ;

#endif

#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - Shell minimal
 * Return: Always 0
 */
int main(void)
{
	int interactive_mode = isatty(STDIN_FILENO) && isatty(STDERR_FILENO);
	char *line = NULL, *token = NULL, *args[10];
	size_t len = 0;
	int i, status = 0;

	if (interactive_mode) 		/* if it's an interactive mode display the prompt */
		printf("($) ");		/* get a line in the standard input */
	while (getline(&line, &len, stdin) != -1) 	/* while a line is enter do the loop */
	{
		i = 0;
		token = strtok(line, " \t\n"); 		/* the strtok move the line in an array of "word" */
		while (token && i < 9)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}
		args[i] = NULL;
		if (args[0] && strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(status);
		}
		else if (args[0] && strcmp(args[0], "env") == 0)
		{
			print_env();
			status = 0;
		}
		else if (args[0]) 	/* execute the commande */
			status = simple_execute_command(args);
		if (interactive_mode) 		/* if it's an interactive mode display the prompt */
			printf("($) ");
	}
	free(line);	/* free memory of line */
	return (status);	/* return code to the system */
}

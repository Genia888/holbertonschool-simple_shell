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

	/* if it's an interactive mode display the prompt */
	if (interactive_mode)
		printf("($) ");
	/* get a line in the standard input while a line is enter do the loop */
	while (getline(&line, &len, stdin) != -1)
	{
		/* take care of number of parameters of the command line */
		i = 0;
		/* the strtok move the line in an array of "word" */
		token = strtok(line, " \t\n");
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
		/* execute the commande */
		else if (args[0])
			status = simple_execute_command(args);
		/* if it's an interactive mode display the prompt */
		if (interactive_mode)
			printf("($) ");
	}
	free(line); /* free memory */
	return (status); /* return code to the system */
}

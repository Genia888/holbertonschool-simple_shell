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
	int i;

	/* if it's an interactive mode display the prompt */
	if (interactive_mode)
		printf("($) ");
	/* get a line in the standard input */
	/* while a line is enter do the loop */
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
			if (interactive_mode)
				exit(2);
			else
				exit(2);
		}

		/* execute the commande */
		if (args[0])
			simple_execute_command(args);
		/* if it's an interactive mode display the prompt */
		if (interactive_mode)
			printf("($) ");
	}

	/* free memory of line */
	free(line);
	/* return code to the system */
	return (0);
}

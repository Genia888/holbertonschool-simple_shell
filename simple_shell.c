#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Shell minimal
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, *token = NULL, *args[10];
	size_t len = 0;
	int i;

	printf("$");
	/* get a line in the standard input */
	while (getline(&line, &len, stdin) != -1)
	{
		/* take care of number of parameters of the command line */
		i = 0;
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
			exit(0);
		}

		/* execute the commande */
		if (args[0])
			simple_execute_command(args);
		printf("$");
	}

	/* free memory of line */
	free(line);
	return (0);
}

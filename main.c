#include "main.h"
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

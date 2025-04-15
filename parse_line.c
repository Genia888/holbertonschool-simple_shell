#include "shell.h"

/**
 * parse_line - Tokenizes a line into arguments
 * @line: input string
 * Return: array of args
 */
char **parse_line(char *line)
{
	char *token, **args;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}

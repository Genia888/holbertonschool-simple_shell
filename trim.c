#include "shell.h"

/**
 * trim_spaces - Remove leading/trailing spaces
 * @str: input string
 * Return: trimmed string (same pointer)
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;

	end[1] = '\0';
	return (str);
}

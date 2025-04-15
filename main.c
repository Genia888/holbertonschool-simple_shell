#include "shell.h"

/**
 * main - Entry point of the shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		args = parse_line(line);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		if (handle_builtin(args) == 0)
		{
			free_args(args);
			continue;
		}

		execute_command(args, av[0]);
		free_args(args);
	}
	free(line);
	return (0);
}

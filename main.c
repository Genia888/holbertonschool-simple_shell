#include "shell.h"

/**
 * main - Entry point of the shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL, *clean_line = NULL;
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
		{
			free(line);
			break;
		}

		clean_line = trim_spaces(line);
		args = parse_line(clean_line);

		if (!args || !args[0])
		{
			free_args(args);
			_exit(127);
		}

		if (handle_builtin(args))
			execute_command(args, av[0]);

		free_args(args);
	}
	return (0);
}

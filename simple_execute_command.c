#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * simple_execute_command - Execute une commande
 * @args: Tableau d'arguments
 *
 * Return: Code de retour du programme exécuté, ou 2 si erreur execve
 */
int simple_execute_command(char **args)
{
	pid_t pid;
	int status;

	if (!args || !args[0])
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (2);
	}
	else if (pid == 0)
	{
		
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(2);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (2);
	}
	return (0);
}


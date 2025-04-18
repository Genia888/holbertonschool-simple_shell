#include "simple_shell.h"
#include <stdio.h>

void print_env(void)
{
	extern char **environ;
	int i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

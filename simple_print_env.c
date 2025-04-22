#include "simple_shell.h"
#include <stdio.h>

/**
 * print_env - display environment variable
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

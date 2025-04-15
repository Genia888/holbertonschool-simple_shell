#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


#include <stdio.h>
#include <unistd.h>


/**
 * main - args
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 1;
	size_t characters;
	pid_t child_pid;
	int status;
	char *argv[2];

	printf("$");
	do {
		characters = getline(&buffer, &bufsize, stdin);
		buffer[characters - 1] = '\0';
		argv[0] = buffer;
		argv[1] = NULL;
		printf("1%s", buffer);
		printf("2%s", argv[0]);
		printf("3%s", argv[1]);
		child_pid = fork();
		if (child_pid == -1)
			printf("error");
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
		printf("$");
	} while (characters > 0);

	return (0);
}

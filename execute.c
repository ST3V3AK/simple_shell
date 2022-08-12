#include "simple_shell.h"


/**
 * prompt - prints an input string on the terminal
 * @message: message
 *
 * Return
 */

void prompt(char *message)
{
	int i;
	int n = strlen(message);

	for (i = 0; i < n; i++)
		putchar(msg[i]);
	putchar(' ');
}

/**
 * execute - executes an input command
 * @av: input string
 *
 * Return: void.
 */

void execute(char *av[])
{
	int child_pid;
	int status;

	if (av[0] == NULL)
	{
		perror(":( No input\n");
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork err: ");
		exit(1);
	}
	if (child_pid == 0)
	{
		if ((execve(av[0], av, environ)) == -1)
		{
			perror(":( \n");
			exit(1);
		}
	}
	wait(&status);
	printf("After wait? %d %d\n", child_pid, status);
}
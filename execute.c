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
		_putchar(message[i]);
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
		if (av[1] != NULL)
		{
			write(STDERR_FILENO, ERR_MSG, 30)
				exit(1);

		}
		if ((execve(av[0], av, environ)) == -1)
		{
			write(STDERR_FILENO, ERR_MSG, 30);
			exit(1);
		}
	}
	wait(&status);
}

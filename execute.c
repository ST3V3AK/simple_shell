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


		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(1);
		}
		if (av[0] == NULL)
		{
			printf(":( No input\n");
		}
		else if (child_pid == 0)
		{
			if ((execve(av[0], av, environ)) == -1)
			{
				perror(":( \n");
				free(buffer);
				exit(1);
			}
		}
		wait(&status);
		printf("After wait?\n");
	return (0);
}

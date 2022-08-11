#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - get PID and PPID
 *
 * Return: Always 0.
 */

extern char **environ;
int main(void)
{
	pid_t child_pid;
	pid_t ppid;
	int status;
	int i = 0, num_tokens = 0;
	size_t size;
	char *buffer, *copy, *token, *delim = " \n";
	char **av;

	while (1)
	{
		/* PROMPT*/
		printf(":) ");
		if ((getline(&buffer, &size, stdin)) == -1)
		{
			printf("Exiting shell....\n");
			free(buffer);
			exit(0);
		}
		/*PROMPT*/

		/*PARSING*/
		/*create a copy of string*/
		copy = malloc(sizeof(char) * strlen(buffer));
		if (
		strcpy(copy, buffer);

		/*get number of tokens*/
		token = strtok(buffer, delim);
		while (token)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		/*.........................*/

		av = malloc(sizeof(char *)  * num_tokens);

		/*create 2d array*/
		token = strtok(copy, delim);
		for (i = 0; i < num_tokens; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			av[i] = token;
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		/*........................*/
		/*PARSE*/

		/*EXECUTE*/
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
		free(buffer);
		printf("After free buffer?\n");
		free(copy);
		printf("After free copy?\n");
		for (i = 0; i < num_tokens; i++)
		{
			printf("In the loop?\n");
			free(av[i]);
		}
		printf("Maybe outside the loop?\n");
		free(av);
	}

	return (0);
}

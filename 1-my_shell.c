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
	int i = 0, j, num_tokens = 0;
	size_t size;
	char *buffer, *copy, *token, *delim = " \n";
	char **av;

	printf(":) ");
	j = getline(&buffer, &size, stdin);

	/*create a copy of string*/
	copy = malloc(sizeof(char) * strlen(buffer));
	printf("After malloc\n");
	strcpy(copy, buffer);

	/*create sting of tokens*/
	token = strtok(buffer, delim);
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	
	av = malloc(sizeof(char *)  * num_tokens);

	token = strtok(copy, delim);
	for (i = 0; i < num_tokens; i++)
	{
		av[i] = malloc(sizeof(char) * strlen(token));
		av[i] = token;
		token = strtok(NULL, delim);
	}
	av[i] = NULL;

	while (j >= 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			return (-1);
		}
		if (child_pid == 0)
		{
			execve(av[0], av, environ);
			perror(":( \n");
			continue;
		}
		else
		{
			wait(&status);
			printf(":) ");
			j = getline(&buffer, &size, stdin);
			continue;
		}
	}
	printf("Exiting shell....\n");
	
	for (i = 0; i < num_tokens; i++)
		free(av[i]);
	free(av);
	return (0);
}

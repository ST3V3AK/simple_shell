#include "main.h"
/**
 * main - Task 0.1
 * Return: Nothing
 */
int main(void)
{
	char *prompt, *token, *delim, *buf, *copy_buf, **cmdl;
	size_t len_tokens, bufsize;
	ssize_t read_chars;
	int i, status, number_of_tokens;

	delim = "\n ";
	prompt = "#cisfun$ ";
	printf("%s", prompt);
	while ((read_chars = getline(&buf, &bufsize, stdin)) != -1)
	{
		copy_buf = malloc(sizeof(char) * strlen(buf));
		strcpy(copy_buf, buf);
		len_tokens = tokenslen(copy_buf, delim);
		number_of_tokens = tokens_in_string(copy_buf, delim);
		free(copy_buf);
		cmdl = malloc(sizeof(char *) * (len_tokens + 1));
		copy_buf = malloc(sizeof(char) * strlen(buf));
		strcpy(copy_buf, buf);
		token = strtok(copy_buf, delim);
		for (i = 0; i < number_of_tokens; i++)
		{
			cmdl[i] = malloc(sizeof(char) * strlen(token));
			cmdl[i] = token;
			token = strtok(NULL, delim);
		}
		cmdl[i] = NULL;
		if (fork() == 0)
		{
			if (i == 1)
			{
				execve(cmdl[0], cmdl, environ);
				perror("./shell");
			}
			else
				dprintf(2, "./shell: No such file or directory\n");
		}
		wait(&status);
		printf("%s", prompt);
	}
	return (0);
}

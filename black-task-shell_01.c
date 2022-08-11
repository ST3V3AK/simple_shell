#include "main.h"


int main(void)
{
	char *token __attribute__((unused));
	char *delim;
	char *tmp __attribute__((unused));
	int number_of_tokens __attribute__((unused));
	size_t len_tokens;
	char *buf;
	size_t bufsize;
	ssize_t read_chars __attribute__((unused));
	char *copy_buf __attribute__((unused));
	char *prompt __attribute__((unused));
	char **cmdl __attribute__((unused));
	int i;
	int status;

	delim = "\n ";
	prompt = "#cisfun$ ";
	printf("%s", prompt);
	while((read_chars = getline(&buf, &bufsize, stdin)) != -1)
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
		free(copy_buf);

		if (fork() == 0)
		{
			if (i == 1)
			{
				execve(cmdl[0], cmdl, NULL);
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














































































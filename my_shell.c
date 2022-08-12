#include "simple_shell.h"

/**
 * main - runs shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *welcome, *msg, *err_msg;
	char *buffer = NULL, *copy;
	char **argv, *delim = " \n";
	size_t size;
	int read_chars, n_tok;
	int height, status, mode;

	welcome = "Starting shell....";
	msg = ":) ";
	err_msg = ":( ";

	prompt(welcome);
	check_mode(&mode);
	while (1)
	{
		/*Get commands*/
		prompt(msg);
		read_chars = getline(&buffer, &size, stdin);
		if (read_chars == -1)
		{
			perror(err_msg);
			exit(1);
		}

		copy = copy_string(buffer);
		n_tok = num_tok(copy, delim);
		free(copy);
		copy = copy_string(buffer);
		argv = create_array(copy, delim, &height);
		execute(argv);
		free_grid(argv, height);
		if (mode == 0)
			exit(0);
	}
	return (0);
}

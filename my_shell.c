#include "simple_shell.h"

/**
 * main - runs shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *welcome, *msg, *exit_msg;
	char *buffer = NULL, *copy;
	char **argv, *delim = " \n";
	size_t size;
	int read_chars; /*n_tok = 0*/
	int status;

	welcome = "Starting shell....\n";
	exit_msg = "\nExiting shell.....\n";
	msg = ":) ";

	prompt(welcome);
	check_mode(&status);
	while (1)
	{
		/*Get commands*/
		prompt(msg);
		read_chars = getline(&buffer, &size, stdin);
		if (read_chars == -1)
		{
			prompt(exit_msg);
			exit(1);
		}

		copy = copy_string(buffer);
		/*n_tok = num_tok(copy);*/
		/*free(copy);*/
		copy = copy_string(buffer);
		argv = create_array(copy, delim);
		execute(argv);
		/*free_grid(argv, n_tok);*/
		if (status == 0)
		{
			free(copy);
			exit(0);
		}
	}
	return (0);
}

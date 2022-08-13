#include "simple_shell.h"


/**
 * check_mode - checks if launched in interactive or non inttactive
 * @status: stores the outout of isatty
 *
 * Return: Always 0;
 */

void check_mode(int *status)
{
	if ((isatty(STDIN_FILENO)) == 1)
		*status = 1;
	else
		*status = 0;
}

/**
 * free_grid - frees a 2d array
 * @grid: a 2-dimentinal array
 * @height: number of pointers in the array
 *
 * Return: void
 */

void free_grid(char **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		if (grid[i] != NULL)
			free(grid[i]);
		i++;
	}
	free(grid);
}

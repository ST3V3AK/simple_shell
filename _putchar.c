#include "simple_shell.h"

/**
 * _putchar - prints a character
 * @c: input character
 *
 * Return: 0 for success and others for failure
 */

int _putchar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}

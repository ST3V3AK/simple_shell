#include "simple_shell.h"

/**
 * _putchar - prints a character
 * @c: input character
 *
 * Return: void
 */

void _putchar(char c)
{
        if (c != NULL)
                write(STDIN_FILENO, c, 1);
}

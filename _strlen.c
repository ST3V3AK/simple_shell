#include "simple_shell.h"
#include <stddef.h>

/**
 * _strlen - returns length of string
 * @s: the string to measure
 *
 * Return: the integer length
 */
int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen(s + 1));
	return (0);
}

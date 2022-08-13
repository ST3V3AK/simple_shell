#include <unistd.h>

/**
 * _putchar - prints a single unsigned character
 * Prototype: int _putchar(char c);
 * @c: single caracter
 *
 * Return: the character written as an unsigned char cast to
 * an int or EOF on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

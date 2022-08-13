#include "simple_shell.h"

/**
 * *_strcpy - copies memory area
 * @dest: destination memory area
 * @src: memory area to copy from
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i, n;

	n = _strlen(src);
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

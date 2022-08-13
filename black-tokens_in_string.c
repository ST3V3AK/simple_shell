#include "main.h"

/**
 * tokens_in_string - computes the number of tokens in a string
 * @str: string to tokenize
 * @delim: characters delimiter used to split @str
 *
 * Return: the number of tokens
 */

int tokens_in_string(char *str, char *delim)
{
	int n;
	char *token;

	token = strtok(str, delim);
	n = 0;
	while (token)
	{
		token = strtok(NULL, delim);
		n++;
	}
	return (n);
}

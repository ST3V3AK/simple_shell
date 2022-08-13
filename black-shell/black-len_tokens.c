#include "main.h"

/**
 * tokenslen - computes the sum of all lengths of tokens
 * Prototype: size_t tokenslen(char *str, char *delim)
 * @str: a string to tokenize
 * @delim: characters delimiter used to split @str
 *
 * Return: the sum of all length of tokens, or 0 on failure.
 */

size_t tokenslen(char *str, char *delim)
{
	char *good_str;
	char *token;
	char *temp = NULL;
	int len_temp;

	good_str = malloc(sizeof(char) * strlen(str));
	strcpy(good_str, str);
	token = strtok(good_str, delim);
	temp = token;
	len_temp = 0;
	while (token)
	{
		len_temp += strlen(temp);
		temp = token;
		token = strtok(NULL, delim);
	}
	return (len_temp);
}

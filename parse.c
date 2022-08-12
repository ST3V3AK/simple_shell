#include "simple_shell.h"


/**
 * copy_string - copies a string to a new memory location
 * @str: input string
 *
 * Return: pointer to new string
 */

char *copy_string(char *str)
{
	char *copy;

	copy = malloc(sizeof(char) * strlen(str));
	if (copy == NULL)
	{
		perror(":( Malloc Failed\n");
		free(copy);
		return (NULL);;
	}
	strcpy(copy, buffer);
	return(copy);
}

/**
 * num_tok - returns the number of tokens in a string
 * @str: input string
 * @delim: delimiter character
 *
 * Return: thenumber of tokens.
 */

int num_tok(char *str, char *delim)
{
	char *token;
	int num_tokens = 0;

	token = strtok(str, delim);
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	return(num_tokens);
}

/**
 * create_array - creates an array of pointers to tokens
 * @str: input string
 * @delim: delimiter
 * @height: address of an int that holds the arrays height
 * @width: address of an int that holds the arrays width
 *
 * Return: a 2d array of pointers to strings
 */

char **create_array(char *str, char *delim, int *height)
{
	char **arr;
	char *token;
	int size, i, j;

	size = num_tok(str, delim);
	arr = malloc(sizeof(char *)  * size);

	if (arr == NULL)
	{
		perror(":( arr: Malloc failed\n");
		free(arr);
		return (NULL);
	}

	/*create 2d array*/

	token = strtok(str, delim);
	for (i = 0; i < size; i++)
	{
		arr[i] = malloc(sizeof(char) * strlen(token));
		if (arr[i] == NULL)
		{
			for (j = 0; j <= i; j++)
				free(arr[j]);
			free(arr);
			perror(":( arr[i]: malloc failed\n");
			return (NULL);
		}
		arr[i] = token;
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	height = &size;
	return (arr);
}

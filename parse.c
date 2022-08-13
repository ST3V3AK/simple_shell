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
		perror(":( ");
		free(copy);
		exit(1);
	}
	_strcpy(copy, str);
	return(copy);
}

/**
 * num_tok - returns the number of tokens in a string
 * @str: input string
 *
 * Return: thenumber of tokens.
 */

int num_tok(char *str)
{
	char* delim = " ";
	int i= 0;
	int num_tokens = 0;

	while (str[i])
	{
		if (str[i] == delim[0])
			num_tokens++;
		i++;
	}
	return(num_tokens + 1);
}

/**
 * create_array - creates an array of pointers to tokens
 * @str: input string
 * @delim: delimiter
 * @height: address of an int that holds the arrays height
 *
 * Return: a 2d array of pointers to strings
 */

char **create_array(char *str, char *delim)
{
	char **arr;
	char *token;
	int size, i;

	size = num_tok(str);
	arr = malloc(sizeof(char *)  * size);
	if (arr == NULL)
	{
		perror(":( ");
		free(arr);
		exit(1);
	}

	/*create 2d array*/
	token = strtok(str, delim);
	for (i = 0; i < size; i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		if (arr[i] == NULL)
		{
			free_grid(arr, i);
			perror(":( ");
			exit(1);
		}
		arr[i] = token;
		token = strtok(NULL, delim);
	}
	return (arr);
}

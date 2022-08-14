#include "main.h"

/**
 * list_path - builds linked list for the directories hold
 * by the environment variable $PATH
 *
 * 
 */

listpath_t *list_path_dir(void)
{
	size_t len_path = strlen(_getenv("PATH"));
	char *path = malloc(sizeof(char) * len_path);
	char *delim = "$PATH=:";
	char *token;
	listpath_t *head;

	head = NULL;
	strcpy(path, _getenv("PATH"));
	token = strtok(path, delim);
	while (token)
	{
		add_nodepath_end(&head, token);
		token = strtok(NULL, delim);
	}

	return (head);
}






























































































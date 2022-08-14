#include "main.h"

/**
 * add_nodepath_end - adds a new node at the end of a
 * path_t list
 * Prototype:
 * path_t *add_nodepath_end
 * (path_t **head, const char *name);
 *
 * @head: points to the first element
 * @name: name to be hold by the name field of a path_t
 * node
 *
 * Return: the address of the head or NULL on
 * failure
 *
 */

listpath_t *add_nodepath_end(listpath_t **head, const char *name)
{
	listpath_t *new_node, *last_node;

	last_node = *head;

	new_node = malloc(sizeof(new_node));
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->name = strdup(name);
	new_node->next = NULL;

	if (!(*head))
		*head = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}

	return (new_node);
}

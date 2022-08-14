#include "main.h"

/**
 * free_list - free a list_t list
 * Prototype: void free_list(list_t *head);
 * @head: points to the first element of a list_t list
 * Return: nothing
 */
void free_path_list(listpath_t *head)
{
	listpath_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->name);
		free(head);
		head = temp;
	}
}

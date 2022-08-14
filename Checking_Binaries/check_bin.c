#include "main.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	listpath_t *head;
	char *path_terminated_slash;
	char *path_and_binary;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}

	i = 0;
	while (i < 3)
	{
		head = list_path_dir();
		while (head)
		{
			if (head->name == NULL)
				printf("[0] (nil)\n");
			else
				printf("%s\n", head->name);
			head = head->next;
		}
		printf("==========================\n");
		i++;
	}
	return (0);
}


















#include "main.h"

/**
 * Write a program that looks for files in the current PATH
 * Usage: _which filename
 *
 */

char *found_bin(char *binary_name)
{
	struct dirent *dir_entry;
	DIR *dirp;
	listpath_t *head;
	int i;
	char *path_bin;
	char *path_bin_middle_slashed;


	head = list_path_dir();
	while (head)
	{
		dirp = opendir(head->name);
		if (dirp == NULL)
		{
			perror("opendir");
			exit(EXIT_FAILURE);
		}

		while ((dir_entry = readdir(dirp)) != NULL)
		{
			if (strcmp(binary_name,dir_entry->d_name) == 0)
			{
				path_bin = malloc(sizeof(char) *
				(strlen(head->name) +
				strlen("/")));
				path_bin = strcat(head->name, "/");

				path_bin_middle_slashed = malloc(sizeof(char) *
				(strlen(path_bin) + strlen(dir_entry->d_name)));
				path_bin_middle_slashed = strcat(head->name,
				dir_entry->d_name);
			}
		}
		closedir(dirp);
		head = head->next;
	}
	return (path_bin_middle_slashed);
}
int main(int ac, char **av)
{
	int i;

	if (ac < 2 || av == NULL)
	{
		dprintf(2, "Usage: _which <directory name>\n");
		exit (EXIT_FAILURE);
	}

	i = 1;
	while(av[i])
	{
		printf("%s\n", found_bin(av[i]));
		i++;
	}
	return (EXIT_SUCCESS);
}




































































































#include "main.h"

/**
 * _which - look for existing binary in $PATH
 * Prototype: char *_which(char *binary_name)
 * @binary_name: name of the binary
 * Return: the full path of the binary
 *
 * Usage: _which <binary name>
 * Example:
 *	$ ./which ls
 *	Output: /bin/ls
 */

char *_which(char *binary_name)
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



































































































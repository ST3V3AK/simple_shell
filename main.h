#ifndef MAIN_H
#define MAIN_H

/** header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdarg.h>

/** Global variables */
extern char **environ;


/** Structures */

/**
 * listpath_s - directory contained in the environment
 * variable $PATH
 *
 * @name: directory name
 * @next: points to the next directory
 *
 * Description: List of directories contained in the
 * environment variable $PATH
 *
 */
typedef struct listpath_s
{
	char *name;
	struct listpath_s *next;
} listpath_t;


/** Prototypes functions */
size_t tokenslen(char *str, char *delim);
int tokens_in_string(char *str, char *delim);


char *_which(char *binary_name);


char *_getenv(const char *name);
void print_path(void);
/** Prototypes for Singly Linked List of PATH */
listpath_t *add_nodepath_end(listpath_t **head, const char *name);
size_t print_listpath(const listpath_t *h);
listpath_t *list_path_dir(void);
void free_path_list(listpath_t *head);









#endif /** MAIN_H */

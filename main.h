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

/** Global variables */
extern char **environ;


/** Structures */


/** Prototypes functions */
size_t tokenslen(char *str, char *delim);
int tokens_in_string(char *str, char *delim);

#endif /** MAIN_H */

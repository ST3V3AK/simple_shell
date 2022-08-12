#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#define FROM_GNU
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void check_mode(int *status);
void prompt(char *message);
char *copy_string(char *str);
int num_tok(char *str, char *delim);
char **create_array(char *str, char *delim, int *height);
void execute(char *av[]);
void free_grid(char **grid, int height);
#endif

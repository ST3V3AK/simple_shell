#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

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
int num_tok(char *str);
char **create_array(char *str, char *delim);
void execute(char *av[]);
void free_grid(char **grid, int height);
int _strlen(char *s);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#define ERR_MSG ":( No such file or directory\n"
#endif

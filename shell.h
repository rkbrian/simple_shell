#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

int _putchar(char c);
void _puts(char *str);
char **tokenize(char *str);
char *read_cmd(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int new_size);
char *_strncpy(char *dest, char *src, int n);
void execute(char **cmd);

#endif

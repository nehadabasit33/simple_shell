#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_ARG 10
#define MAX_PATH 25
extern char **environ;
/* functions.c */
int _strcspn(char *str, char *stop);
void _parsecmd(char *command, char **argv);
int _putchar(char c);
int _strlen(char *str);
int _strncmp(char *str1, char *str2, int len);
/* functons2.c */
char *_getenv(char *name);
int _strcmp(char *str1, char *str2);
char *_getpath(char **argv, char *dir);
void _printenv(void);
int _process(char **argv, char *command, char **av);
/* functions3.c */
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _builtin(char **argv, char *command);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *del);
/* functions4.c*/
void ignore_stderr(void);
int _atoi(char *str);

#endif

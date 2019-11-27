
#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;
int _cd(char **args);
int _help(char **args);
int e_exit(char **args);
int _env(__attribute__((unused))char **args);
char *_strcat(char *s1, char *s2);
char *_whichy(char *ch);
/*ssize_t _getline(char **buffer, size_t *bufsize, FILE *f);*/
void sigintHandler (int sig_num);
char **_strtok(char *line);
char *_getline();
#endif

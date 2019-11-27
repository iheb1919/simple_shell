
#include "holberton.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 64
#define split " \t\r\n\a"
/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */
char **_strtok(char *line)
{
  int bufsize = SIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, split);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += SIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, split);
  }
  tokens[position] = NULL;
  return tokens;
}

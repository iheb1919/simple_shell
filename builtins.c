#include "shell.h"
/**
 * _cd - function that
 * @args: array of strings
 * Return:
 */
int _cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}
int _help(__attribute__((unused))char **args){printf("HELLOWORD\n");
  return (1);}
int e_exit(__attribute__((unused))char **args){

return 0;}
/**
* print_env - function that prints environ
* Return: 1
*/
int  _env(__attribute__((unused))char **args)
{
extern char **environ;
int i;
char *s = *environ;
for (i = 1; s != NULL; i++)
{
printf("%s\n", s);
s = environ[i];
}
 return (1);
}

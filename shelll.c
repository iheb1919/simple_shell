#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <signal.h>
#include <sys/stat.h>
/**
 *
 *
 *
 */

int exec(char *st, char *st2)
{

}

/**
 * _getline - function that get a line
 * @buffer: pointer to pointer
 * @bufsize: pointer
 * @f: pointer
*/
ssize_t _getline(char **buffer, size_t *bufsize, FILE *f)
{
return (getdelim(buffer, bufsize, '\n', f));
}
/**
 * _getline - function that get a line
 * @buffer: pointer to pointer
 * @bufsize: pointer
 * @f: pointer
*/
void sigintHandler(int sig_num)
{
signal(SIGINT, sigintHandler);

putchar('\n');
}
/**
 * _strcat - function that concat strings
 * @s1: pointer
 * @s2: pointer
 * Return: s1 on sauccess
 */
char *_strcat(char *s1, char *s2)
{
char *result = NULL;
int l1 = 0, l2 = 0, i = 0, k = 0;

for (l1 = 0; s1[l1]; l1++)
;

for (l2 = 0; s2[l2]; l2++)
;

result = malloc(sizeof(char) * (l1 + l2 + 1));
if (!result)
return (NULL);
for (i = 0; s1[i]; i++)
result[i] = s1[i];
k = i;
for (i = 0; s2[i]; i++)
result[k + i] = s2[i];
k = k + i;

result[k] = '\0';
return (result);
}
/**
 * _whichy - function search for path
 * @ch: pointer
 *Return: path on succcess
 */
char *_whichy(char *ch)
{
char *env, *tok, *p, *t[100];
int i, k;
struct stat buf;

env = getenv("PATH");
tok = strtok(env, ":");
t[0] = tok;
k = 1;
while (tok != NULL)
{
tok = strtok(NULL, ":");
t[k] = tok;
k++;
}
k = 0;
while (t[k])
{
p = _strcat(_strcat(t[k], "/"), ch);
if (stat(p, &buf) == 0)
{
return (p);
}
k++;
}
return (NULL);
}
/**
 * main - function
 *
 *Return: 0 Always
 */
int main(void)
{
char *buffer, *env;
size_t bufsize = 64;
pid_t p;
char *argv[100], *tok;
int i, status, j = 0, ex = 0;
signal(SIGINT, sigintHandler);
buffer = (char *)malloc(bufsize * sizeof(char));
if (buffer == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}
printf("#cisfun$ ");
while (_getline(&buffer, &bufsize, stdin) != -1)
{
if (strcmp(buffer, "exit\n") == 0)
return (0);
else if (strcmp(buffer, "env\n") == 0)
{
env = *(environ);
while (env)
{
printf("%s\n", env);
j++;
env = *(environ + j);
}
}
i = 0;
argv[i] = strtok(buffer, " \t\r\n\a");
while (argv[i] != NULL)
{
argv[++i] = strtok(NULL, " \t\r\n\a");
}
p = fork();
if (p == 0)
{
ex = execve(argv[0], argv, NULL);
if (ex == -1)
{
ex = execve(_whichy(argv[0]), argv, NULL);
if (ex == -1)
perror("Eror:");
}
}
if (ex == -1)
exit (-1);
wait(0);
printf("#cisfun$ ");
}
return (0);
}


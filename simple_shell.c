#include <header.h>
/**
 * main - function that provide a simple unix line interpreter
 * @argc: input
 * @argv: input
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
(void)argc;
int T = 1;
char *buf;
char *env[2];
int x, i, a;
char *c, *token = NULL, *cmd, *path;
size_t size = 500;
buf = (char *)malloc(size * sizeof(char));
c = (char *)malloc (size * sizeof(char));
while (T == 1)
{
printf("#cisfun$ ");
getline(&buf, &size, stdin);
strcpy(c, buf);
token = strtok(c, "\n");
path = (char *)malloc (size * sizeof(char));
strcpy(path, token);
token = strtok(buf, "/");
cmd = malloc(sizeof(token));
while (token != NULL)
{
cmd = token;
token = strtok(NULL, "/");
}
env[0] = cmd;
env[1] = NULL;
x = fork();
if (x == 0)
{
a = execve(path, env, NULL);
if (a != 0)
printf("%s :No such file or directory\n", argv[0]);
}
else if (x > 0)
wait(0);
}
if (strcmp(buffer, "exit\n") == 0)
{
free(buffer);
free(tok);
exit(1);
}
bf = getline(&buffer, &bufsize, stdin);
if (bf == EOF)
{
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
return (1);
}

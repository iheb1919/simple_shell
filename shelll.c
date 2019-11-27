#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <signal.h>
extern char **environ;
#include <sys/stat.h>



//getline
ssize_t _getline(char **buffer, size_t *bufsize, FILE *f)
{
return getdelim (buffer, bufsize, '\n', f);
}
//exit ctrl + c
void sigintHandler (int sig_num)
{
signal(SIGINT, sigintHandler);
//fflush(stdout);
putchar('\n');
}

int main(void)
{
  int ex = 0;
    char *buffer, *env;
    size_t bufsize = 64;
    pid_t p;
    char *argv[100];
    int i, status, j;
    char *tok;
    signal(SIGINT ,sigintHandler);
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    printf("#cisfun$ ");
    while (_getline(&buffer,&bufsize,stdin) != -1)
    {
       if (strcmp(buffer,"exit\n") == 0)
	return(0);
      else if (strcmp(buffer,"env\n") == 0)
	{
	  j = 0;
	  env = *(environ);
	  while (env)
	    {
	      printf("%s\n", env);
	      j++;
	      env = *(environ + j);
	    }
	    }
  i = 0;
  argv[i] = strtok(buffer , " \t\r\n\a");
  while (argv[i] != NULL)
  {
      argv[++i] = strtok(NULL , " \t\r\n\a");
  }
//exe (argv);
  p = fork();
  if (p == 0)
  {
    ex =execve(argv[0], argv,NULL);
    if (ex == -1 )
      {ex = execve(_whichy(argv[0]), argv++ , NULL);
        if(ex ==-1)
	  { 
	      perror("Eror:");}
      }
  }
  /* else if (p > 0)
    {
      if((p == wait(&status)) < 0)
	perror("wait");
	}*/
  if (ex == -1)
    exit (-1);
  wait(0);


  printf("#cisfun$ ");
    }
return (0);
}


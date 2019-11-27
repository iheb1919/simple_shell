#include "shell.h"
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

char *_whichy(char *ch)
{
char *env, *tok, *p, *t[100] ;
int i, k;
struct stat buf;

env = getenv("PATH");
tok = strtok(env, ":");
t[0] = tok;
k = 1;
while (tok)
          {
          tok = strtok(NULL , ":");
          t[k] = tok;
          k++;
          }
  k = 0;
  while (t[k])
          {
          p = _strcat(_strcat(t[k],"/"),ch);
          if (stat(p, &buf) == 0)
          {
                return(p);
                }
        k++;
        }
return(NULL);
}

#include "header.h"

extern char **environ;

void printallenv(void)
{
  char newline = '\n';
  char **env;
  char *gotenv;
  int i = 0;

  env = environ;
  while (env[i])
    {
      gotenv = env[i];
      write(STDOUT_FILENO, &gotenv, _strlen(gotenv));
      write(STDOUT_FILENO, &newline, 1);
      i++;
    }
}

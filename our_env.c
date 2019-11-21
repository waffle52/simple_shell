#include "header.h"

extern char** environ;

char *_getenv(char *name)
{
  int i, j, length = 0;
  char *token = NULL;
  char *environ_string = NULL;

  while (name[length])
    length++;

  environ_string = malloc(sizeof(char) * length);
  for (i = 0; environ[i] != NULL; i++)
    {
      j = 0;
      while (j < length)
	{
	  environ_string[j] = environ[i][j];
	  j++;
	}
      if (_strcmp(name, environ_string) == 0)
	{
	  token = strtok(environ[i], "=");
	  token = strtok(NULL, "=");
	  return (token);
	}
    }
  free(environ_string);
  return (NULL);
}

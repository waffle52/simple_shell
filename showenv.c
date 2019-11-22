#include "header.h"

void showenv(char **environ)
{
  char newline = '\n';
  int count, length;

  printf("%s\n", environ[1]);
  for (count = 0; environ[count] != NULL; count++)
    {
      length = _strlen(environ[count]);
      write(STDOUT_FILENO, environ[count], length);
      write(STDOUT_FILENO, &newline, 1);
    }
}

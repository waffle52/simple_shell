#include "header.h"

char *_getenv(char *name)
{
	int i, j;

	i = 0;
	while (name[i])
		i++;

	j = 0;
	while(*environ[j])
	{
		if (_strcmp(name, environ[j]) == 0)
		    return(&environ[j][i+1]);
	}
		return(NULL);
}

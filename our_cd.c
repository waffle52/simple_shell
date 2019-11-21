#include "header.h"

int our_cd(char *path)
{
	char *hold;
	int ret;

       	if (path == NULL)
       	{
       		hold = _getenv("HOME");
       		ret = chdir(hold);
       		return(ret);
       	}
       	else if (_strcmp(path, "..") == 0)
       	{
       		hold = handledotdot("OLDPWD");
		ret = chdir(hold);
       		return(ret);
       	}
       	else if (_strcmp(path,"-") == 0)
       	{
       		hold = _getenv("OLDPWD");
       		ret = chdir(hold);
       		return(ret);
       	}
       	else if (_strcmp(path,".") == 0)
       	{
       		hold = _getenv("PWD");
		ret = chdir(hold);
       		return(ret);
       	}
/* for all others with absolute or relative path */
       	else
       	{
		if (access(path, F_OK) == 0)
		{
			ret = chdir(path);
			return (ret);
		}
		else
			perror("cd failed");
       	}
	return (0);
}
/*      cd ..     */
char *handledotdot(char *path)
{
	int i;
	char *original = path;
	char *dup;
	char *token;
	int numtoks;

	original = _getenv("OLDPWD");
	dup = _strdup(original);

	token = strtok(dup, "/");
	numtoks = 0;
	while(token != NULL)
	{
		token = strtok(NULL, "/");
		numtoks++;
	}
	numtoks = numtoks - 1;

	token = strtok(original, "/");

	i = 0;
	while(i < numtoks)
	{
		token = strtok(NULL, "/");
	}
	return (token);
}

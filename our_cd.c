#include "header.h"

int our_cd(char *path, char **environ)
{
	char *hold;
	int ret;

/*cd by itself still doesn't work?? */
       	if (path == NULL || _strcmp(path, "~") == 0)
       	{
/* goal: old directory before you change directory */
		ret = chdir(_getenv("HOME", environ));
       		return(ret);
       	}
       	else if (_strcmp(path, "..") == 0)
       	{
		ret = chdir("..");
		return (ret);
       	}
       	else if (_strcmp(path,"-") == 0)
       	{
/* added if it is not null, to go ahead! */
		if (_getenv("OLDPWD", environ) != NULL)
		{
			hold = _getenv("OLDPWD", environ);
/* need to update environment's cd and pwd */

			ret = chdir(hold);


			return(ret);
		}
/*		else */
/*else you just stay in the same working directory? */
/*		{
			perror("OLDPWD is not set\n");
			hold = _getenv("PWD");
			ret = chdir(hold);
			return (ret);
		}   */
       	}
       	else if (_strcmp(path,".") == 0)
       	{
		hold = _getenv("PWD", environ);
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

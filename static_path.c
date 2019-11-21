#include "header.h"

extern char **environ;

char *_strcat(char *dest, char *src)
{
	int i, j, k, num;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	while (src[j] != '\0')
		j++;

	if (i < j)
		num = j;
	else if (i >= j)
		num = i;

	for (k = 0; k < num; k++)
	{
		if (num == j)
			dest[k + num - 1] = src[k];
		else
			dest[k + num] = src[k];
	}

	return (dest);
}

char *static_path(char *user_command)
{
	char *env_string;
	char *token;

	env_string = _getenv("PATH");
	/* Gets rid of the variable name. We only want what's inside */
	token = strtok(env_string, "=");
	token = strtok(NULL, "=");

	token = strtok(env_string, ":");
	while (token != NULL)
	{
		token = _strcat(token, "/");
		token = _strcat(token, user_command);

		if (access(token, F_OK) == 0)
		return (token);

		token = strtok(NULL, ":");
	}

	return (user_command);
}

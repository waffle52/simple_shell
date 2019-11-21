#include "header.h"

extern char **environ;

char *cmd_cpy(char *dest, char *src, char *usr_cmd)
{
	int i, j;
	char slash = '/';

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = slash;
	for (i++, j = 0; usr_cmd[j] != '\0'; j++, i++)
		dest[i] = usr_cmd[j];

	dest[i] = '\0';
	return (dest);
}

char *static_path(char *user_command, char *env_string)
{
	char *token = NULL;
	char *token2 = NULL;
	char *dupe_str = NULL;
	int i;

	dupe_str = _strdup(env_string);
	token = strtok(dupe_str, ":");

	while (token != NULL)
	{
		token2 = malloc(sizeof(char) * (_strlen(token) + _strlen(user_command) + 1));
		for (i = 0; i < (_strlen(token) + _strlen(user_command) + 1); i++)
			token2[i] = '\0';
		cmd_cpy(token2, token, user_command);

		if (access(token2, F_OK) == 0)
			return (token2);

		token = strtok(NULL, ":");
		free(token2);
	}
	return (user_command);
}

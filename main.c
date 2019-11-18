#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t commandnum, i = 0;
	char **array;
	char *commandcopy, *token;
	char delim[] = " ";

	write(STDOUT_FILENO,"$",1);

	getline(&command, &command_size, stdin);

	for(i = 0; command[i]; i++)
	{
		if (command[i] == '\n')
			command[i] = '\0';
	}

	commandcopy = _strdup(command);

	token = strtok(commandcopy, delim);
	while(token)
	{
		write(STDOUT_FILENO, token, _strlen(token));
		token = strtok(NULL, delim);
		commandnum++;
	}

	array = malloc(sizeof(char *) * (commandnum + 1));
	if (array == NULL)
		return(-1);

	token = strtok(commandcopy, delim);
	i = 0;
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	if (fork() == 0)
		execve(array[0], array, NULL);
	else
		wait(NULL);
	return(0);
}

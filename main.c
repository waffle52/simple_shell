#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t commandnum = 0, i = 0;
	char **array;
	char *commandcopy = NULL, *token;
	char delim[] = " ";
	int run = 1; /* later changed by exit() */

	while(run)
	{
		commandnum = 0;
		command_size = 0;
		write(STDOUT_FILENO,"$ ",2);

		getline(&command, &command_size, stdin);

		for(i = 0; command[i]; i++)
		{
			if (command[i] == '\n')
				command[i] = '\0';
				}

		commandcopy = _strdup(command);
		/*	printf("test: %s", commandcopy); */
		token = strtok(commandcopy, delim);
		/*	printf("test: %s", token); */
		while(token != NULL)
		{
			token = strtok(NULL, delim);
			commandnum++;
		}

		array = malloc(sizeof(char *) * (commandnum + 1));

		token = strtok(command, delim);
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
		free(command);
		free(commandcopy);
		free(array);

		command = NULL;
		commandcopy = NULL;
	}
	return(0);
}

#include "header.h"

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t commandnum = 0, i = 0;
	char **array;
	char *commandcopy = NULL, *token;
	char delim[] = " ";
	int status = 0;

	/* (void) signal(SIGINT, SIG_IGN); */
	/* (void) signal(SIGTERM, handler); */

	while(1)
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

		token = strtok(commandcopy, delim);

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

		if (_strcmp("exit", array[0]) == 0)
		{

			if (array[1] != NULL)
			{
				status = _atoi(array[1]);
			}

			free(command);
			free(commandcopy);
			free(array);

		        exit(status);
		}

		/*	if (_strcmp("cd", array[0]) == 0)
		{

		}*/

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

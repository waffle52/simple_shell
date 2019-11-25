#include "header.h"

int main(int argc, char *argv[], char **env_cmd)
{
	char *command = NULL;
	size_t command_size = 0;
	size_t commandnum = 0, i = 0;
	char **array;
	char *commandcopy = NULL, *token;
	char delim[] = " ";
	int status = 0, run = 0;
	char *env_string = NULL;
	pid_t pid;
	struct data mine;
	(void)argc, (void)argv;

	signal(SIGINT, SIG_IGN);
	env_string = _getenv("PATH", env_cmd);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	while((run = getline(&command, &command_size, stdin)))
	{
		commandnum = 0;
		command_size = 0;

		if (run == EOF)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		for(i = 0; command[i]; i++)
		{
			if (command[i] == '\n')
				command[i] = '\0';
		}

		command = strtok(command, "#");
	        commandcopy = _strdup(command, &mine);

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

		if (array[0] != NULL && _strcmp("exit", array[0]) == 0)
		{

			if (array[1] != NULL)
			{
				status = _atoi(array[1]);
			}

			free(command);
			free(commandcopy);
			free(array);

		        pid = fork();
			while(pid != 1)
			{
				_exit(status);
			}
		}

		if (array[0] != NULL && _strcmp("cd", array[0]) == 0)
		{
			our_cd (array[1], env_cmd);
		}

		if (array[0] != NULL && _strcmp("env", array[0]) == 0)
		{
			showenv(env_cmd);
		}

		if (array[0] != NULL)
		{
			array[0] = static_path(array[0], env_string, &mine);

			free(mine.buffer);
			/* needed to free exact amount but stops program from working free(mine.token2); */
		}

		if (fork() == 0)
		{
			execve(array[0], array, NULL);
			free(mine.token2);
			exit(status);
		}
		else
			wait(NULL);

		free(command);
		free(commandcopy);
		free(array);
		fflush(stdin);

		command = NULL;
		commandcopy = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
        freeAll(&mine);
	return(0);
}
